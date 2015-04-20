#include "qguiapplication.h"

#include "environment.h"

using namespace HmiGui;

Environment::Environment(QObject *parent)
    : QObject(parent)
{

}

Environment* Environment::instance()
{
    static Environment *self = 0;
    if (!self)
        self = new Environment(qApp);

    return self;
}

QString Environment::themesFolder() const
{
    return m_themesFolder;
}

void Environment::setThemesFolder(const QString &value)
{
    m_themesFolder = value;
}
