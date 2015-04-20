#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>

#include "hmigui_global.h"
#include "themescollection.h"

class QQmlEngine;
class QQmlContext;

namespace HmiGui {

class HMIGUI_EXPORT ThemeManager : public QObject
{
    Q_OBJECT

public:
    explicit ThemeManager(QQmlEngine *engine, QQmlContext *context, QObject *parent = 0);
    ~ThemeManager();

    void collectThemes(const QString &jsonPath, const QString &themesRootFolder);

    QString currentTheme() const;
    void setCurrentTheme(const QString theme);

public slots:
    void changeTheme(const QString &theme);

signals:
    void currentThemeChanged(QString theme);

private:
    bool loadTheme(const QString &theme);
    void activateTheme(const QString &theme);

    QString m_currentTheme;
    ThemesCollection m_themesCollection;
    QQmlEngine *m_engine;
    QQmlContext *m_context;

};


}
#endif // THEMEMANAGER_H
