#ifndef HMIHOME_H
#define HMIHOME_H

#include <QObject>

#include "hmihome_global.h"
#include "hmimodule.h"

class QQmlContext;

namespace HmiHome {
class HomeController;

class HMIHOME_EXPORT HomeMain : public HmiBase::HmiModule
{
    Q_OBJECT
public:
    explicit HomeMain(QObject* parent = 0);
    virtual HmiStateMachine::State *createApplicationStateTree(HmiStateMachine::State *parentState) Q_DECL_OVERRIDE;
    virtual void setContextProperties(QQmlContext *context) Q_DECL_OVERRIDE;

private:
    HomeController *m_controller;
};

}
#endif // HMIHOME_H
