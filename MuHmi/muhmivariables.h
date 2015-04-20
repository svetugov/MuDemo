#ifndef MUHMIVARIABLES_H
#define MUHMIVARIABLES_H

#include "ihmivariables.h"
#include "themescollection.h"

class MuHmiVariables : public QObject, public HmiBase::IHmiVariables
{
    Q_OBJECT

public:
    MuHmiVariables(QObject *parent = 0);
    ~MuHmiVariables();

protected:
    virtual int windowWidth() const Q_DECL_OVERRIDE;
    virtual int windowHeight() const Q_DECL_OVERRIDE;
    virtual QString rootQmlPath() const Q_DECL_OVERRIDE;
    virtual QString hmiModulePluginFolder() const Q_DECL_OVERRIDE;
    virtual QString hmiModuleQmlFolder() const Q_DECL_OVERRIDE;
    virtual HmiStateMachine::State *modulesRootState() const Q_DECL_OVERRIDE;
    virtual HmiBase::HmiModuleId initialModuleId() const Q_DECL_OVERRIDE;
    virtual QString themesFolder() const Q_DECL_OVERRIDE;
};

#endif // MUHMIVARIABLES_H
