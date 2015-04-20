#ifndef STATE_H
#define STATE_H

#include <QState>

#include "hmistatemachine_global.h"
#include "stateid.h"

namespace HmiStateMachine {

class HMISTATEMACHINE_EXPORT State : public QState
{
    Q_OBJECT
public:
    State(const StateId name, QState* parent);

    StateId name() const { return m_name; }
    bool isActive() { return m_isActive; }

protected:
    void onEntry(QEvent* event) Q_DECL_OVERRIDE;
    void onExit(QEvent* event) Q_DECL_OVERRIDE;

protected:
    StateId m_name;
    bool m_isActive;
};

}
#endif // STATE_H
