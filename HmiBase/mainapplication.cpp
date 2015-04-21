#include <QQmlContext>
#include <QDir>
#include <QPluginLoader>
#include <QQmlEngine>

// Base
#include "mainapplication.h"
#include "ihmivariables.h"
#include "ihmimodulecreator.h"
#include "hmimodule.h"

// Gui
#include "viewmanager.h"
#include "thememanager.h"
#include "environment.h"

// State Machine
#include "statemachine.h"
#include "state.h"

using namespace HmiBase;

MainApplication::MainApplication(int &argc, char **argv, IHmiVariables *hmiVariables) :
    QGuiApplication(argc, argv)
  , m_hmiVariables(hmiVariables)
{
    // Set main window size
    m_quickView.setWidth(m_hmiVariables->windowWidth());
    m_quickView.setHeight(m_hmiVariables->windowHeight());

    // Add import pathes
    m_quickView.engine()->addImportPath(m_hmiVariables->importFolder());

    // Load root qml and show main window
    QUrl rootQml = QUrl::fromLocalFile(m_hmiVariables->rootQmlPath());
    m_quickView.setSource(rootQml.path());
    m_quickView.show();

    // Themeing
    HmiGui::Environment::instance()->setThemesFolder(m_hmiVariables->themesFolder());
    qmlRegisterType<HmiGui::Painter>("HmiGui", 1, 0, "Painter");
    m_themeManager = new HmiGui::ThemeManager(m_quickView.engine(), m_quickView.rootContext(), this);
    m_themeManager->collectThemes(m_hmiVariables->themesFolder() + QLatin1Literal("themesDescriptor.json"),
                                  m_hmiVariables->themesFolder());
    // Set default theme
    m_themeManager->changeTheme("main");
    m_quickView.rootContext()->setContextProperty("themeManager", m_themeManager);


    // Create view manager
    m_viewManager = new HmiGui::ViewManager(m_quickView.engine(), m_quickView.rootObject(), this);

    // Load modules from plugins
    loadHmiModules();
    foreach(HmiBase::HmiModule *module, m_hmiModules) {
        module->setContextProperties(m_quickView.rootContext());
        m_viewManager->collectModuleViewsFromJson(module->name()
                                                  , m_hmiVariables->hmiModuleQmlFolder()
                                                  + module->name()
                                                  + QLatin1Literal("/viewDescriptor.json")
                                                  , m_hmiVariables->hmiModuleQmlFolder());
    }

    // Ignite state machine
    launchStateMachine();
}

void MainApplication::loadHmiModules()
{
    QDir pluginsDir = QDir(m_hmiVariables->hmiModulePluginFolder());
    if (!pluginsDir.exists()) {
        qDebug() << "Directory with UI applications doesn't exist.";
        return;
    }

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));

        // Check that we have found an Hmi Module Plugin, if not, skip it
        const QJsonObject metaData = loader.metaData();
        QStringList metaDataKeys = metaData.keys();
        if (!metaDataKeys.contains(QLatin1String("IID")) ||
                metaData.value(QLatin1String("IID")) != QLatin1String(IHmiModuleCreator_IID)) {
            continue;
        }

        QObject *plugin = loader.instance();
        if (plugin) {
            qDebug() << "Plugin" << fileName << "loaded successfully";
            HmiModule* app = qobject_cast<IHmiModuleCreator*>(plugin)->createApplication(this);
            m_hmiModules.insert(app->name(), app);
        }
        else
            qDebug() << "Failed to load plugin:" << fileName << "with error:" << loader.errorString();
    }
}

void MainApplication::launchStateMachine()
{
    // Create root state
    HmiStateMachine::State *rootState = m_hmiVariables->modulesRootState();
    HmiStateMachine::StateMachine::instance()->setInitialState(rootState);

    // Include modules states to state machine
    foreach (HmiModule* module, m_hmiModules)
        module->createApplicationStateTree(rootState);

    // Set state machine initital state
    rootState->setInitialState(m_hmiModules.value(m_hmiVariables->initialModuleId())->rootState());

    // Launch machine
    HmiStateMachine::StateMachine::instance()->start();
}
