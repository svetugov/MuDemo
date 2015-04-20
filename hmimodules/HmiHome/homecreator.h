#ifndef HOMECREATOR_H
#define HOMECREATOR_H

#include <QObject>

#include "hmihome_global.h"
#include "ihmimodulecreator.h"
#include "homemain.h"

namespace HmiHome {

class HMIHOME_EXPORT HomeCreator : public QObject, public HmiBase::IHmiModuleCreator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID IHmiModuleCreator_IID)
    Q_INTERFACES(HmiBase::IHmiModuleCreator)

public:
    HomeCreator() {}
    HmiBase::HmiModule* createApplication(QObject* parent) Q_DECL_OVERRIDE { return new HomeMain(parent); }
};

}
#endif // HOMECREATOR_H
