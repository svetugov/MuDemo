#include "transitionrequestevent.h"

using namespace HmiStateMachine;

TransitionRequestEvent::TransitionRequestEvent(EventId name, QVariant data)
    : Event()
    , m_name(name)
    , m_data(data)
{
}

EventId TransitionRequestEvent::name() const
{
    return m_name;
}

QVariant TransitionRequestEvent::data() const
{
    return m_data;
}
