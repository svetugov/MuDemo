#ifndef VIEWSTATE_H
#define VIEWSTATE_H

#include "hmistatemachine_global.h"
#include "state.h"
#include "viewid.h"


namespace HmiStateMachine {

class HMISTATEMACHINE_EXPORT ViewState : public State
{
    Q_OBJECT
public:
    explicit ViewState(HmiGui::ViewId id, QState *parent = 0);
    HmiGui::ViewId viewId() const { return m_viewId; }

protected:
    void onEntry(QEvent* event) Q_DECL_OVERRIDE;
    void onExit(QEvent* event) Q_DECL_OVERRIDE;

private:
    HmiGui::ViewId m_viewId;
    ViewState* m_backState;
    QSignalTransition* m_backTransition;
};

}
#endif // VIEWSTATE_H
