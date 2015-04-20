#include "QGuiApplication"

#include "tools.h"

using namespace HmiGui;

Tools::Tools(QObject *parent)
    : QObject(parent)
{

}

Tools* Tools::instance()
{
    static Tools* self = 0;
    if (!self)
        new Tools(qApp);

    return self;
}

