#include <QQuickItem>

#include "viewloader.h"

using namespace HmiGui;

ViewLoader::ViewLoader(QQmlEngine* qmlEngine, View* view, QObject* parent) :
    QObject(parent)
  , m_qmlEngine(qmlEngine)
  , m_view(view)
{
}

void ViewLoader::load()
{
    m_component = new QQmlComponent(m_qmlEngine, m_view->url, QQmlComponent::PreferSynchronous, this);
    if (m_component->isLoading())
        connect(m_component, &QQmlComponent::statusChanged, this, &ViewLoader::onLoadingStatusChanged);
    else
        onLoadingStatusChanged();
}

void ViewLoader::onLoadingStatusChanged()
{
    switch(m_component->status()) {
        case QQmlComponent::Error:
        {
            m_view->status = View::ViewStatusError;
            m_view->errorString = m_component->errorString();
            emit loadingComplete(m_view->id);
            this->deleteLater();
            break;
        }
        case QQmlComponent::Ready:
        {
            QObject* quickItem = m_component->create();
            quickItem->setParent(this->parent());
            m_view->item = qobject_cast<QQuickItem*>(quickItem);
            if (m_view->item) {
                m_view->status = View::ViewStatusReady;
            }
            else {
                m_view->status = View::ViewStatusError;
                if (quickItem)
                    delete(quickItem);
            }
            emit loadingComplete(m_view->id);
            this->deleteLater();
            break;
        }
        default:
            break;
    }
}
