#ifndef VIEW
#define VIEW

#include <QUrl>
#include <QQuickItem>

#include "viewid.h"

namespace HmiGui {

struct View
{
    enum ViewStatus {
        ViewStatusNull,
        ViewStatusError,
        ViewStatusReady
    };

    ViewId id;
    QUrl url;
    QString moduleName;
    ViewStatus status;
    QString errorString;
    QQuickItem* item;

    View(ViewId id,
         QUrl url,
         QString moduleName = "",
         ViewStatus status = ViewStatusNull,
         QString errorString = "",
         QQuickItem* item = 0) :
        id(id),
        url(url),
        moduleName(moduleName),
        status(status),
        errorString(errorString),
        item(item)
    {}
};

}
#endif // VIEW

