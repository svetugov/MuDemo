#include <QtGui/QGuiApplication>
#include "mainapplication.h"
#include "muhmivariables.h"

int main(int argc, char *argv[])
{
    MuHmiVariables muHmiVariables(qApp);
    HmiBase::MainApplication app(argc, argv, static_cast<HmiBase::IHmiVariables*>(&muHmiVariables));
    return app.exec();
}
