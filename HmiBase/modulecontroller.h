#ifndef MODULECONTROLLER_H
#define MODULECONTROLLER_H

#include <QObject>

#include "hmibase_global.h"

namespace HmiBase {

class HMIBASE_EXPORT ModuleController : public QObject
{
    Q_OBJECT
public:
    ModuleController(QObject *parent = 0);
    ~ModuleController();

public slots:
    virtual void back();
};
 }
#endif // MODULECONTROLLER_H
