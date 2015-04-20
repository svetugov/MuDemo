#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <QStateMachine>
#include <QHash>

#include "hmistatemachine_global.h"
#include "viewid.h"

namespace HmiStateMachine {
class ViewState;

class HMISTATEMACHINE_EXPORT StateMachine : public QStateMachine
{
    Q_OBJECT
public:
    static StateMachine* instance();
    ViewState* state(HmiGui::ViewId id) const { return m_viewStates.value(id, 0); }

signals:
    void goBack();

protected:
    void appendViewState(ViewState* state);


private:
    explicit StateMachine(QObject *parent = 0);

    QHash<HmiGui::ViewId, ViewState*> m_viewStates;


    friend class HmiStateMachine::ViewState;
};

}
#endif // STATEMACHINE_H
