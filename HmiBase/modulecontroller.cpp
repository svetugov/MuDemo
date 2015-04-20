#include "modulecontroller.h"
#include "statemachine.h"

using namespace HmiBase;

ModuleController::ModuleController(QObject *parent)
    : QObject(parent)
{

}

ModuleController::~ModuleController()
{

}

void ModuleController::back()
{
    HmiStateMachine::StateMachine::instance()->goBack();
}
