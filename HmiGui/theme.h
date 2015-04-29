#ifndef THEME_H
#define THEME_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QHash>

#include "hmigui_global.h"
#include "painter.h"

namespace HmiGui {
typedef QHash<QString, QUrl> AnimationsCollection;
typedef QHash<QString, QUrl> StylesCollection;

struct Theme
{
    QString id;
    QUrl descriptorUrl;
    Painter *painter;
    AnimationsCollection animationsCollection;
    StylesCollection stylesCollection;
    bool ready;
    QString errorString;

    Theme( QString id
           ,QUrl descriptorUrl
           ) :
        id(id)
      ,descriptorUrl(descriptorUrl)
      ,painter(0)
      ,animationsCollection()
      ,stylesCollection()
      ,ready(false)
      ,errorString("")
    {}
};


typedef QHash<QString, Theme*> ThemesCollection;
}

#endif // THEME_H
