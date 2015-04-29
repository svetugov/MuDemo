#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

#include "hmigui_global.h"

namespace HmiGui {

class HMIGUI_EXPORT Settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Orientation orientation READ orientation WRITE setOrientation NOTIFY orientationChanged)

public:
    enum Orientation {
        Horizontal,
        Vertical
    };
    Q_ENUMS(Orientation)

    static Settings* instance();
    ~Settings();

    Orientation orientation() const;
    void setOrientation(const Orientation &orientation);

signals:
    void orientationChanged(Orientation value);

private:
    explicit Settings(QObject *parent = 0);

    Orientation m_orientation;
};
}
#endif // SETTINGS_H
