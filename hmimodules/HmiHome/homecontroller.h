#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "modulecontroller.h"

namespace HmiHome {

class HomeController : public HmiBase::ModuleController
{
    Q_OBJECT
public:
    HomeController(QObject *parent = 0);
    ~HomeController();

public slots:
    void showFameHall();
};

}
#endif // HOMECONTROLLER_H
