#include "qguiapplication.h"

#include "settings.h"

using namespace HmiGui;

Settings::Settings(QObject *parent)
    : QObject(parent)
    , m_orientation(Horizontal)
{

}

Settings::~Settings()
{

}

Settings* Settings::instance()
{
    static Settings *self = 0;
    if (!self)
        self = new Settings(qApp);

    return self;
}

Settings::Orientation Settings::orientation() const
{
    return m_orientation;
}

void Settings::setOrientation(const Orientation &orientation)
{
    if (m_orientation != orientation) {
        m_orientation = orientation;
        emit orientationChanged(m_orientation);
    }
}
