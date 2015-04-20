#ifndef EVENTUALTRANSITION_H
#define EVENTUALTRANSITION_H

#include <QVariant>

#include "hmistatemachine_global.h"
#include "conditionaltransition.h"
#include "eventid.h"

namespace HmiStateMachine {

class HMISTATEMACHINE_EXPORT EventualTransition : public ConditionalTransition
{
public:
    explicit EventualTransition(EventId eventId, QState* source);

    void setTriggerEventData(QVariant data);
    QVariant transitionData() const;

protected:
    virtual bool eventTest(QEvent *event);

private:
    bool testEventData(const QVariant &data) const;

    EventId m_triggerEventId;
    QVariant m_triggerEventData;
    QVariant m_transitionData;
};

}
#endif // EVENTUALTRANSITION_H
