#ifndef CONDITIONALTRANSITION_H
#define CONDITIONALTRANSITION_H

#include <QAbstractTransition>

#include "hmistatemachine_global.h"

namespace HmiStateMachine {

class HMISTATEMACHINE_EXPORT ConditionalTransition : public QAbstractTransition
{
    Q_OBJECT
public:
    explicit ConditionalTransition(QState *source = 0);

    void setAllowTransition(bool arg);

signals:
    void transitionTest();
    void transitionFailed();

protected:
    virtual bool eventTest(QEvent *event);
    virtual void onTransition(QEvent *event);

private:
    bool m_allowTransition;
    bool m_allowTransitionDefault;
};

}
#endif // CONDITIONALTRANSITION_H
