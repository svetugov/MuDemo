#ifndef VIEWLOADER_H
#define VIEWLOADER_H

#include <QObject>

#include "view.h"

class QQmlEngine;
class QQmlComponent;

namespace HmiGui {

class ViewLoader : public QObject
{
    Q_OBJECT
public:
    explicit ViewLoader(QQmlEngine* qmlEngine, View* view, QObject* parent = 0);
    void load();

signals:
    void loadingComplete(const ViewId &id);

private slots:
    void onLoadingStatusChanged();

private:
    QQmlEngine* m_qmlEngine;
    View* m_view;
    QQmlComponent* m_component;
};

}
#endif // VIEWLOADER_H
