#ifndef TRANSITIONREQUESTEVENT_H
#define TRANSITIONREQUESTEVENT_H

#include <QVariant>

#include "hmistatemachine_global.h"
#include "event.h"
#include "eventid.h"

namespace HmiStateMachine {

class HMISTATEMACHINE_EXPORT TransitionRequestEvent : public Event<TransitionRequestEventType>
{
public:
    explicit TransitionRequestEvent(EventId name, QVariant data = 0);

    EventId name() const;
    QVariant data() const;

private:
    EventId m_name;
    QVariant m_data;
};

}

#endif // TRANSITIONREQUESTEVENT_H
