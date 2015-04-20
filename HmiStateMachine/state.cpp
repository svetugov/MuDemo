#include "state.h"

using namespace HmiStateMachine;

State::State(const StateId name, QState* parent) :
    QState(parent)
  , m_name(name)
  , m_isActive(false)
{
}

void State::onEntry(QEvent *event)
{
    Q_UNUSED(event);
    m_isActive = true;
}

void State::onExit(QEvent *event)
{
    Q_UNUSED(event);
    m_isActive = false;
}
