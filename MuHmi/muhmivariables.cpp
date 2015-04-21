#include "muhmivariables.h"
#include "statemachine.h"
#include "state.h"
#include "theme.h"


MuHmiVariables::MuHmiVariables(QObject *parent)
    : QObject(parent)
    , HmiBase::IHmiVariables()
{

}

MuHmiVariables::~MuHmiVariables()
{

}

int MuHmiVariables::windowWidth() const
{
    return 800;
}

int MuHmiVariables::windowHeight() const
{
    return 480;
}

QString MuHmiVariables::rootQmlPath() const
{
    return QString(QStringLiteral(BUILD_ROOT_DIR) + "/qml/main.qml");
}

QString MuHmiVariables::hmiModulePluginFolder() const
{
    return QString(QStringLiteral(BUILD_ROOT_DIR) + "/hmimodules/");
}

QString MuHmiVariables::hmiModuleQmlFolder() const
{
    return QString(QStringLiteral(BUILD_ROOT_DIR) + "/qml/");
}

HmiStateMachine::State* MuHmiVariables::modulesRootState() const
{
    return new HmiStateMachine::State("modulesRootState", qobject_cast<QState*>(HmiStateMachine::StateMachine::instance()));
}

HmiBase::HmiModuleId MuHmiVariables::initialModuleId() const
{
    return "HmiHome";
}

QString MuHmiVariables::themesFolder() const
{
    return QString(QStringLiteral(BUILD_ROOT_DIR) + "/themes/");
}

QString MuHmiVariables::importFolder() const
{
    return QString(QStringLiteral(BUILD_ROOT_DIR) + "/imports");
}
