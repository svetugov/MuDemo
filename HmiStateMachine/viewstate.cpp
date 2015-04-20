#include <QSignalTransition>
#include <QDebug>

#include "viewstate.h"
#include "stateguisupporter.h"
#include "statemachine.h"

using namespace HmiStateMachine;

ViewState::ViewState(HmiGui::ViewId viewId, QState *parent) :
    State(viewId, parent)
  , m_viewId(viewId)
  , m_backState(0)
  , m_backTransition(0)
{
    // State machine stores all view states to have an access to a state by viewId.
   StateMachine::instance()->appendViewState(this);
}

void ViewState::onEntry(QEvent *event)
{
    Q_UNUSED(event);

    qDebug() << Q_FUNC_INFO << m_name;

    // Setup back button transition
    m_backState = StateMachine::instance()->state(HmiGui::StateGuiSupporter::instance()->topView());
    if (m_backState) {
        if (!m_backTransition)
            m_backTransition = addTransition(StateMachine::instance(), SIGNAL(goBack()), m_backState);
        else if (m_backTransition->targetState() != qobject_cast<QAbstractState*>(m_backState))
            m_backTransition->setTargetState(m_backState);
    }

    // Show bound view
    HmiGui::StateGuiSupporter::instance()->showView(m_viewId);
}

void ViewState::onExit(QEvent *event)
{
    Q_UNUSED(event);

    qDebug() << Q_FUNC_INFO << m_name;

    // Hide bound view
    HmiGui::StateGuiSupporter::instance()->hideView(m_viewId);
}
