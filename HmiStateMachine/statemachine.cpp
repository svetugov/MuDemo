#include <QGuiApplication>

#include "statemachine.h"
#include "viewstate.h"

using namespace HmiStateMachine;

StateMachine::StateMachine(QObject *parent) :
    QStateMachine(parent)
{
}

StateMachine* StateMachine::instance()
{
    static StateMachine* self = 0;
    if (!self)
        self = new StateMachine(qApp);

    return self;
}

void StateMachine::appendViewState(ViewState *state)
{
    m_viewStates.insert(state->viewId(), state);
}
