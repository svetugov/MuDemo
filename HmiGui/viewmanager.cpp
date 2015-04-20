#include <QQuickItem>
#include <QQmlEngine>

#include <QDir>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

#include "viewmanager.h"
#include "viewloader.h"

using namespace HmiGui;

ViewManager::ViewManager(QQmlEngine* qmlEngine, QQuickItem* rootItem, QObject *parent) :
    StateGuiSupporter(parent)
  , m_qmlEngine(qmlEngine)
  , m_rootItem(rootItem)
  , m_viewToShow("")
  , m_topView("")
  , m_viewsCollection()
{
    // Give state machine an access to this class.
    m_stateGuiSupporterInstance = this;
}

View* ViewManager::getViewFromCollection(const ViewId &id)
{
    QHash<ViewId, View*>::const_iterator it = m_viewsCollection.find(id);
    if (it == m_viewsCollection.end()) {
        qCritical() << Q_FUNC_INFO << "There is no such view in the collection:" << id;
        return 0;
    }
    else
        return it.value();
}

void ViewManager::showView(const ViewId &id)
{
    View* view = getViewFromCollection(id);
    if (view) {
        m_viewToShow = id;
        if (view->status == View::ViewStatusReady) {
            QQuickItem* item = view->item;
            item->setVisible(true);
            m_topView = id;
        }
        else
            loadView(id);
    }
}

void ViewManager::hideView(const ViewId &id)
{
    View* view = getViewFromCollection(id);
    if (view) {
        QQuickItem* item = view->item;
        item->setVisible(false);
    }
}

void ViewManager::loadView(const ViewId &id)
{
    View* view = getViewFromCollection(id);
    if (view) {
        ViewLoader* viewLoader = new ViewLoader(m_qmlEngine, view, this);
        connect(viewLoader, &ViewLoader::loadingComplete, this, &ViewManager::viewLoadingComplete);
        viewLoader->load();
    }
}

void ViewManager::viewLoadingComplete(const ViewId &id)
{
    View* view = getViewFromCollection(id);
    if (view && view->status == View::ViewStatusReady) {
        QQuickItem* item = view->item;
        item->setParent(this);
        item->setParentItem(m_rootItem);

        if (m_viewToShow == id) {
            item->setVisible(true);
            m_topView = id;
        }
    }
    else {
        qCritical() << Q_FUNC_INFO << "view ["<<id<<"] failed to load. Error:" << view->errorString;
    }
}


// View path will be "viewsRootFolder/path" where "path" taken from json.
void ViewManager::collectModuleViewsFromJson(const QString &moduleName,
                                             const QString &jsonPath,
                                             const QString &viewsRootFolder)
{
    // Reading json file and convert it to json document
    QFile file(QDir::toNativeSeparators(jsonPath));
    if (!file.exists()) {
        qCritical() << "JSON file doesn't exist:" + jsonPath;
        return;
    }
    if (!file.open(QFile::ReadOnly)) {
        qCritical() << "Cannot read JSON file:" + jsonPath;
        return;
    }

    const QByteArray jsonData(file.readAll());
    QJsonParseError jsonParseError;
    const QJsonDocument jsonDoc(QJsonDocument::fromJson(jsonData, &jsonParseError));

    if (jsonParseError.error != QJsonParseError::NoError) {
        qCritical() << "JSON file" << jsonPath << "failed to load with error:" << jsonParseError.error;
        return;
    }

    // Finding views in json document
    QJsonObject jsonObject = jsonDoc.object();
    const QString KEY_VIEWS = QLatin1String("views");

    QJsonObject::const_iterator objectsIt = jsonObject.find(KEY_VIEWS);
    if (objectsIt != jsonObject.end()) {
        const QJsonArray views = objectsIt.value().toArray();
        QJsonArray::const_iterator viewsIt;
        int viewObjectIndex = 0;
        for (viewsIt = views.begin(); viewsIt != views.end(); ++viewsIt) {
            const QJsonObject view = (*viewsIt).toObject();

            // Retrieve view "id" from
            const QString KEY_ID = QLatin1String("id");
            objectsIt = view.find(KEY_ID);
            if (objectsIt != view.end()) {
                ViewId id = objectsIt.value().toString();
                if (id.isEmpty()) {
                    qCritical() << "View number" << viewObjectIndex << "has empty id";
                    continue;
                }

                // Retrieve view "file path"
                const QString KEY_FILE = QLatin1Literal("file");
                objectsIt = view.find(KEY_FILE);
                if (objectsIt != view.end()) {
                    QString filePath = objectsIt.value().toString();
                    if (filePath.isEmpty()) {
                        qCritical() << "View number" << viewObjectIndex << "has empty file path";
                        continue;
                    }

                // Create view and put it to views collection
                const QUrl fileUrl = QUrl::fromLocalFile(viewsRootFolder + filePath);
                View *view = new View(id, fileUrl, moduleName);
                if (!m_viewsCollection.contains(id))
                    m_viewsCollection.insert(id, view);
                    qCritical() << "View with id" << id << "added to collection";
                }
            }
            viewObjectIndex++;
        }
    }
}
