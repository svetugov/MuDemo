#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>

#include "hmigui_global.h"
#include "themescollection.h"

class QQmlEngine;
class QQmlContext;
class QJsonObject;

namespace HmiGui {

class HMIGUI_EXPORT ThemeManager : public QObject
{
    Q_OBJECT

public:
    explicit ThemeManager(QQmlEngine *engine, QQmlContext *context, QObject *parent = 0);
    ~ThemeManager();

    void collectThemes(const QString &jsonPath, const QString &themesRootFolder);

public slots:
    void changeTheme(const QString &theme);
    QObject* animation(const QString &name, QObject *parent);
    QObject* style(const QString &name, QObject *parent);

private:
    bool loadTheme(const QString &themeName);
    void activateTheme(const QString &theme);

    QString m_currentTheme;
    ThemesCollection m_themesCollection;
    QQmlEngine *m_engine;
    QQmlContext *m_context;
    QString m_themesRootFolder;

};


}
#endif // THEMEMANAGER_H
