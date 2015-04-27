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

struct Theme
{
    QString id;
    QUrl descriptorUrl;
    Painter *painter;
    AnimationsCollection animationsCollection;
    bool ready;
    QString errorString;

    Theme( QString id
           ,QUrl descriptorUrl
           ) :
        id(id)
      ,descriptorUrl(descriptorUrl)
      ,painter(0)
      ,animationsCollection()
      ,ready(false)
      ,errorString("")
    {}
};


typedef QHash<QString, Theme*> ThemesCollection;
}

#endif // THEME_H
