#ifndef HMIMODULE_H
#define HMIMODULE_H

#include <QObject>

#include "hmibase_global.h"
#include "hmimoduleid.h"

class QQmlContext;

namespace HmiStateMachine {
class State;
}

namespace HmiBase {

class HMIBASE_EXPORT HmiModule : public QObject
{
    Q_OBJECT
public:
    explicit HmiModule(QObject *parent = 0);

    HmiModuleId name() const;
    HmiStateMachine::State* rootState() const;
    virtual HmiStateMachine::State* createApplicationStateTree(HmiStateMachine::State *parent) = 0;
    virtual void setContextProperties(QQmlContext *context) = 0;

protected:
    HmiModuleId m_name;
    HmiStateMachine::State* m_rootState;
};

}
#endif // HMIMODULE_H
