#include <QDebug>

#include "hmimodule.h"

using namespace HmiBase;


HmiModule::HmiModule(QObject *parent) :
    QObject(parent)
  , m_name("")
{
}

HmiModuleId HmiModule::name() const
{
    return m_name;
}

HmiStateMachine::State* HmiModule::rootState() const
{
    return m_rootState;
}
