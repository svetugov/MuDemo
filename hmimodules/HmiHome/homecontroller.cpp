#include "homecontroller.h"
#include "statemachine.h"
#include "hometransitions.h"
#include "transitionrequestevent.h"


using namespace HmiHome;

HomeController::HomeController(QObject *parent)
    : HmiBase::ModuleController(parent)
{

}

HomeController::~HomeController()
{

}

void HomeController::showFameHall()
{
    HmiStateMachine::StateMachine::instance()->postEvent(new HmiStateMachine::TransitionRequestEvent(HomeTransitions::ShowFameHall));
}
