#ifndef IHMIVARIABLES_H
#define IHMIVARIABLES_H

#include <QObject>

#include "hmibase_global.h"
#include "hmimoduleid.h"

namespace HmiStateMachine {
class State;
}

namespace HmiBase {

class HMIBASE_EXPORT IHmiVariables
{
public:
    ~IHmiVariables() {}

protected:
    virtual int windowWidth() const = 0;
    virtual int windowHeight() const = 0;
    virtual QString rootQmlPath() const = 0;
    virtual QString hmiModulePluginFolder() const = 0;
    virtual QString hmiModuleQmlFolder() const = 0;
    virtual HmiStateMachine::State *modulesRootState() const = 0;
    virtual HmiModuleId initialModuleId() const = 0;
    virtual QString themesFolder() const = 0;
    virtual QString importFolder() const = 0;

    friend class MainApplication;
};
}

#endif // IHMIVARIABLES_H
