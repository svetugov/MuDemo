#ifndef EVENT
#define EVENT

#include <QEvent>

namespace HmiStateMachine {

enum EventType {
    TransitionRequestEventType = 1,
    HmiStateMachineEventTypeMax
};

template <EventType offset>

class Event : public QEvent
{
public:
    Event() : QEvent(QEvent::Type(QEvent::User + offset))
    {
    }
};
}
#endif // EVENT

