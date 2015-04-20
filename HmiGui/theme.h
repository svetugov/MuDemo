#ifndef THEME_H
#define THEME_H

#include <QObject>
#include <QString>
#include <QUrl>

#include "hmigui_global.h"
#include "painter.h"

namespace HmiGui {

struct Theme
{
    QString id;
    QUrl url;
    bool ready;
    QString errorString;
    Painter* painter;

    Theme(QString id,
          QUrl url,
          bool ready = false,
          QString errorString = "",
          Painter* painter = 0) :
        id(id),
        url(url),
        ready(ready),
        errorString(errorString),
        painter(painter)
    {}
};

}
#endif // THEME_H
