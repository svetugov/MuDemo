#include <QEvent>

#include "eventualtransition.h"
#include "transitionrequestevent.h"

using namespace HmiStateMachine;

EventualTransition::EventualTransition(EventId eventId, QState* source)
    : ConditionalTransition(source)
    , m_triggerEventId(eventId)
    , m_triggerEventData(QVariant())
    , m_transitionData(QVariant())
{
}

bool EventualTransition::eventTest(QEvent *event)
{
    if (event->type() == QEvent::User + TransitionRequestEventType) {
        TransitionRequestEvent *hmiTransitionEvent = static_cast<TransitionRequestEvent*>(event);
        if (hmiTransitionEvent->name() == m_triggerEventId
                && testEventData(hmiTransitionEvent->data())) {
            m_transitionData = hmiTransitionEvent->data();
            return ConditionalTransition::eventTest(event);
        }
    }
    return false;
}

void EventualTransition::setTriggerEventData(QVariant data)
{
    m_triggerEventData = data;
}

bool EventualTransition::testEventData(const QVariant &data) const
{
    if (m_triggerEventData.isValid()) {
        if (data.type() == m_triggerEventData.type())
            return data == m_triggerEventData;
        else
            return false;
    }
    return true;
}

QVariant EventualTransition::transitionData() const
{
    return m_transitionData;
}
