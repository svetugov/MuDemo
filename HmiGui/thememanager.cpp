#include <QDebug>
#include <QHash>
#include <QDir>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QUrl>

#include "thememanager.h"
#include "theme.h"
#include "painter.h"
#include "tools.h"
#include "environment.h"

using namespace HmiGui;

ThemeManager::ThemeManager(QQmlEngine *engine, QQmlContext *context, QObject *parent)
    : QObject(parent)
    , m_currentTheme("")
    , m_themesCollection()
    , m_engine(engine)
    , m_context(context)
    , m_themesRootFolder("")
{

}

ThemeManager::~ThemeManager()
{

}

void ThemeManager::collectThemes(const QString &jsonPath,
                                 const QString &themesRootFolder)
{
    QJsonDocument jsonDoc;
    if (Tools::generateJsonDocument(jsonPath, jsonDoc)) {
    // Searching "themes" array in json document
    QJsonObject fullDocument = jsonDoc.object();
    QJsonValue themesArrayValue;
    if (Tools::findJsonValue("themes", fullDocument, themesArrayValue)) {
        const QJsonArray themesArray = themesArrayValue.toArray();
        // Searching "id" and "descriptor" for each theme in array
        int index = 0;
        QJsonArray::const_iterator arrayIt;
        for (arrayIt = themesArray.begin(); arrayIt != themesArray.end(); ++arrayIt) {
            QJsonValue idValue;
            if (Tools::findJsonValue("id", (*arrayIt).toObject(), idValue)) {
                QJsonValue descriptorValue;
                if (Tools::findJsonValue("descriptor", (*arrayIt).toObject(), descriptorValue)) {
                    Theme *theme = new Theme(idValue.toString(), QUrl(themesRootFolder + descriptorValue.toString()));
                    m_themesCollection.insert(theme->id, theme);
                    qDebug() << "Theme" << theme->id << "added to collection.";
                }
                else
                    qWarning() << Q_FUNC_INFO << "Failed to find 'descriptor' in theme number:" << index;
            }
            else
                qWarning() << Q_FUNC_INFO << "Failed to find 'id' in theme number:" << index;

            index++;
        }
    }
    else
        qWarning() << Q_FUNC_INFO << "Failed to find 'themes' array.";
    }
}

void ThemeManager::changeTheme(const QString &theme)
{
    if (m_currentTheme == theme) {
        qWarning() << Q_FUNC_INFO << "Selected theme already active:" << theme;
        return;
    }

    Theme* themeObj = m_themesCollection.value(theme);
    if (!themeObj) {
        qWarning() << Q_FUNC_INFO << "Theme" << theme << "failed to load. No such theme:";
        return;
    }

    if (loadTheme(theme))
        activateTheme(theme);
    else
        qWarning() << Q_FUNC_INFO << "Theme" << theme << "failed to load. Error:" << themeObj->errorString;
}

bool ThemeManager::loadTheme(const QString &themeName)
{
    Theme *theme = m_themesCollection.value(themeName);
    if (theme->ready)
        return true;

    // Parsing json file with theme info
    QJsonDocument fullDoc;
    if (!Tools::generateJsonDocument(theme->descriptorUrl.toString(), fullDoc))
        return false;

    QJsonValue idValue;
    if (!Tools::findJsonValue("id", fullDoc.object(), idValue)) {
        qWarning() << Q_FUNC_INFO << "Theme" << themeName << "failed to load. No 'id' in JSON.";
        return false;
    }
    if (idValue.toString() != theme->id) {
        qWarning() << Q_FUNC_INFO << "Theme" << themeName << "failed to load. 'id' has wrong name in JSON.";
        return false;
    }

    QJsonValue painterValue;
    if (!Tools::findJsonValue("painter", fullDoc.object(), painterValue)) {
        qWarning() << Q_FUNC_INFO << "Theme" << themeName << "failed to load. No 'painter' in JSON.";
        return false;
    }

    // Basic info collected. Now we can load theme.
    // Load Painter
    const QString themeFolder = theme->descriptorUrl.toString(QUrl::RemoveFilename);
    QQmlComponent component(m_engine, themeFolder + painterValue.toString(), this);
    if (!component.isReady()) {
        theme->errorString = component.errorString();
        qWarning() << Q_FUNC_INFO << "Theme" << themeName << "failed to load. Cannot load painter /"
                                                             "with error:" << theme->errorString;
        return false;
    }

    Painter* painter = qobject_cast<Painter*>(component.create(m_context));
    if (!painter) {
        qWarning() << Q_FUNC_INFO << "Theme" << themeName << "failed to load. Cannot load painter.";
        return false;
    }

    theme->ready = true;
    theme->painter = painter;

    // Theme loaded. Collect theme's animations.
    QJsonValue animationsValue;
    if (Tools::findJsonValue("animations", fullDoc.object(), animationsValue)) {
        QJsonArray animationsArray = animationsValue.toArray();
        QJsonArray::const_iterator arrayIt;
        int index = 0;
        for (arrayIt = animationsArray.begin(); arrayIt != animationsArray.end(); ++arrayIt) {
            QJsonValue nameValue;
            if (Tools::findJsonValue("name", (*arrayIt).toObject(), nameValue)) {
                QJsonValue fileValue;
                if (Tools::findJsonValue("file", (*arrayIt).toObject(), fileValue)) {
                    const QUrl url = QUrl::fromLocalFile(themeFolder + fileValue.toString());
                    theme->animationsCollection.insert(nameValue.toString(), url);
                }
            }
            index++;
        }
    }

    // Collect styles
    QJsonValue stylesValue;
    if (Tools::findJsonValue("styles", fullDoc.object(), stylesValue)) {
        QJsonArray stylesArray = stylesValue.toArray();
        QJsonArray::const_iterator arrayIt;
        int index = 0;
        for (arrayIt = stylesArray.begin(); arrayIt != stylesArray.end(); ++arrayIt) {
            QJsonValue nameValue;
            if (Tools::findJsonValue("name", (*arrayIt).toObject(), nameValue)) {
                QJsonValue fileValue;
                if (Tools::findJsonValue("file", (*arrayIt).toObject(), fileValue)) {
                    const QUrl url = QUrl::fromLocalFile(themeFolder + fileValue.toString());
                    theme->stylesCollection.insert(nameValue.toString(), url);
                }
            }
            index++;
        }
    }

    qDebug() << "Theme" << themeName << "successfully loaded.";
    return true;
}

void ThemeManager::activateTheme(const QString &theme)
{
    m_context->setContextProperty("painter", m_themesCollection.value(theme)->painter);
    m_currentTheme = theme;
    qDebug() << "Theme" << theme << "activated.";
}

QObject* ThemeManager::animation(const QString &name, QObject *parent)
{
    QUrl url = m_themesCollection.value(m_currentTheme)->animationsCollection.value(name);
    QQmlComponent component(m_engine, url);
    if (component.isReady()) {
        QObject *result = component.create(m_context);
        result->setParent(parent);
        return result;
    }
    else {
        qWarning() << Q_FUNC_INFO << "Animation" << name << "failed to load with error:"
                   << component.errorString();
        return 0;
    }
}


QObject* ThemeManager::style(const QString &name, QObject *parent)
{
    QUrl url = m_themesCollection.value(m_currentTheme)->stylesCollection.value(name);
    QQmlComponent component(m_engine, url);
    if (component.isReady()) {
        QObject *result = component.create(m_context);
        result->setParent(parent);
        return result;
    }
    else {
        qWarning() << Q_FUNC_INFO << "Style" << name << "failed to load with error:"
                   << component.errorString();
        return 0;
    }
}
