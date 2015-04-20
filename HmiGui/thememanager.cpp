#include <QDebug>
#include <QHash>
#include <QDir>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>

#include "thememanager.h"
#include "theme.h"
#include "painter.h"

using namespace HmiGui;

ThemeManager::ThemeManager(QQmlEngine *engine, QQmlContext *context, QObject *parent)
    : QObject(parent)
    , m_currentTheme("")
    , m_themesCollection()
    , m_engine(engine)
    , m_context(context)
{

}

ThemeManager::~ThemeManager()
{

}

QString ThemeManager::currentTheme() const
{
    return m_currentTheme;
}

void ThemeManager::setCurrentTheme(const QString theme)
{
    if (m_currentTheme != theme) {
        m_currentTheme = theme;
        emit currentThemeChanged(m_currentTheme);
    }
}

void ThemeManager::collectThemes(const QString &jsonPath,
                                 const QString &themesRootFolder)
{
    // Reading json file and convert it to json document
    QFile file(QDir::toNativeSeparators(jsonPath));
    if (!file.exists()) {
        qWarning() << Q_FUNC_INFO << "JSON file doesn't exist:" + jsonPath;
        return;
    }
    if (!file.open(QFile::ReadOnly)) {
        qWarning() << Q_FUNC_INFO << "Cannot read JSON file:" + jsonPath;
        return;
    }

    const QByteArray jsonData(file.readAll());
    QJsonParseError jsonParseError;
    const QJsonDocument jsonDoc(QJsonDocument::fromJson(jsonData, &jsonParseError));

    if (jsonParseError.error != QJsonParseError::NoError) {
        qWarning() << Q_FUNC_INFO << "JSON file" << jsonPath << "failed to load with error:" << jsonParseError.error;
        return;
    }

    // Finding themes in json document
    QJsonObject jsonObject = jsonDoc.object();
    const QString KEY_THEMES = QLatin1String("themes");

    QJsonObject::const_iterator objectsIt = jsonObject.find(KEY_THEMES);
    if (objectsIt != jsonObject.end()) {
        const QJsonArray themes = objectsIt.value().toArray();
        QJsonArray::const_iterator themesIt;
        int themeObjectIndex = 0;
        for (themesIt = themes.begin(); themesIt != themes.end(); ++themesIt) {
            const QJsonObject theme = (*themesIt).toObject();

            // Retrieve theme "id"
            const QString KEY_ID = QLatin1String("id");
            objectsIt = theme.find(KEY_ID);
            if (objectsIt != theme.end()) {
                QString id = objectsIt.value().toString();
                if (id.isEmpty()) {
                    qWarning() << Q_FUNC_INFO << "Theme number" << themeObjectIndex << "has empty id";
                    continue;
                }

                // Retrieve theme painter
                const QString KEY_PAINTER = QLatin1Literal("painter");
                objectsIt = theme.find(KEY_PAINTER);
                if (objectsIt != theme.end()) {
                    QString painter = objectsIt.value().toString();
                    if (painter.isEmpty()) {
                        qWarning() << Q_FUNC_INFO << "Theme number" << themeObjectIndex << "has empty file path";
                        continue;
                    }

                    // Create theme and put it to themes collection
                    const QUrl painterUrl = QUrl::fromLocalFile(themesRootFolder + painter);
                    Theme *theme = new Theme(id, painterUrl);
                    if (!m_themesCollection.contains(id))
                        m_themesCollection.insert(id, theme);
                    qDebug() << "Theme with id" << id << "added to collection";
                }
            }
            themeObjectIndex++;
        }
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
        qWarning() << Q_FUNC_INFO << "No such theme:" << theme;
        return;
    }

    if (loadTheme(theme))
        activateTheme(theme);
    else
        qWarning() << Q_FUNC_INFO << "Unable to load theme:" << theme << "Error:" << themeObj->errorString;
}

bool ThemeManager::loadTheme(const QString &theme)
{
    Theme *themeObj = m_themesCollection.value(theme);
    if (themeObj->ready)
        return true;

    QQmlComponent component(m_engine, themeObj->url, this);
    if (component.isReady()) {
        Painter* painter = qobject_cast<Painter*>(component.create(m_context));
        if (!painter)
            return false;

        qDebug() << "Successfully loaded theme:" << theme;
        themeObj->ready = true;
        themeObj->painter = painter;
        return true;
    }
    else {
        themeObj->errorString = component.errorString();
        return false;
    }
}

void ThemeManager::activateTheme(const QString &theme)
{
    m_context->setContextProperty("painter", m_themesCollection.value(theme)->painter);
    m_currentTheme = theme;
    qDebug() << theme << "theme activated.";
}
