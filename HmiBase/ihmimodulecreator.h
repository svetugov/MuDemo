#ifndef IHMIMODULECREATOR_H
#define IHMIMODULECREATOR_H

#include "hmibase_global.h"
#include <QtPlugin>

namespace HmiBase {
class HmiModule;

class HMIBASE_EXPORT IHmiModuleCreator
{
public:
    virtual ~IHmiModuleCreator() {}
    virtual HmiModule* createApplication(QObject* parent) = 0;
};
#define IHmiModuleCreator_IID "com.farce.myhmi.IHmiModuleCreator"
}
Q_DECLARE_INTERFACE(HmiBase::IHmiModuleCreator, IHmiModuleCreator_IID)

#endif // IHMIMODULECREATOR_H
