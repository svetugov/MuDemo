#include <QQmlContext>

#include "homemain.h"
#include "state.h"
#include "viewstate.h"
#include "eventualtransition.h"
#include "statemachine.h"
#include "transitionrequestevent.h"
#include "eventid.h"
#include "homecontroller.h"
#include "hometransitions.h"


using namespace HmiHome;

HomeMain::HomeMain(QObject* parent) :
    HmiBase::HmiModule(parent)
  , m_controller(new HomeController(this))
{
    m_name = "HmiHome";
}

HmiStateMachine::State* HomeMain::createApplicationStateTree(HmiStateMachine::State *parentState)
{
    m_rootState = new HmiStateMachine::State("homeRoot", parentState);
    HmiStateMachine::ViewState* homeViewState = new HmiStateMachine::ViewState("HomeMain", m_rootState);

    HmiStateMachine::ViewState* fameHallState = new HmiStateMachine::ViewState("FameHall", m_rootState);
    HmiStateMachine::EventualTransition * fameHallTransition =
            new HmiStateMachine::EventualTransition(HomeTransitions::ShowFameHall, m_rootState);
    fameHallTransition->setTargetState(fameHallState);

    m_rootState->setInitialState(homeViewState);

    return m_rootState;
}


void HomeMain::setContextProperties(QQmlContext *context)
{
    context->setContextProperty("homeController", m_controller);
}
