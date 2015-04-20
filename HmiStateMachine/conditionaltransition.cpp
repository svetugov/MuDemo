#include "conditionaltransition.h"

using namespace HmiStateMachine;

ConditionalTransition::ConditionalTransition(QState* source)
    : QAbstractTransition(source)
    , m_allowTransition(false)
    , m_allowTransitionDefault(true)
{
}

bool ConditionalTransition::eventTest(QEvent *event)
{
    Q_UNUSED(event);
    m_allowTransition = m_allowTransitionDefault;
    emit transitionTest();
    if (!m_allowTransition)
        emit transitionFailed();
    return m_allowTransition;
}

void ConditionalTransition::setAllowTransition(bool arg)
{
    m_allowTransition = arg;
}

void ConditionalTransition::onTransition(QEvent *event)
{
    Q_UNUSED(event);
}
