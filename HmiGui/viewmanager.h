#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>

#include "hmigui_global.h"
#include "stateguisupporter.h"
#include "view.h"

class QQmlEngine;
class QQuickItem;

namespace HmiGui {

class HMIGUI_EXPORT ViewManager : public StateGuiSupporter
{
    Q_OBJECT
public:
    explicit ViewManager(QQmlEngine* qmlEngine, QQuickItem* rootItem, QObject* parent = 0);

    void showView(const ViewId &id);
    void hideView(const ViewId &id);
    ViewId topView() const { return m_topView; }

    void collectModuleViewsFromJson(const QString &moduleName,
                                    const QString &jsonPath,
                                    const QString &viewsRootFolder);

private slots:
    void viewLoadingComplete(const ViewId &id);

private:
    void loadView(const ViewId &id);
    View* getViewFromCollection(const ViewId &id);
    void activateViewItem(QQuickItem *item);

    QQmlEngine* m_qmlEngine;
    QQuickItem* m_rootItem;
    ViewId m_viewToShow;
    ViewId m_topView;
    QHash<ViewId, View*> m_viewsCollection;

};

}
#endif // VIEWMANAGER_H
