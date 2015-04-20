#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>

namespace HmiGui {
class Tools : public QObject
{
    Q_OBJECT
public:
    static Tools* instance();

private:
    explicit Tools(QObject *parent = 0);
};

}
#endif // TOOLS_H
