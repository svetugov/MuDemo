#ifndef ENVIRONMENT
#define ENVIRONMENT

#include <QObject>

#include "hmigui_global.h"

namespace HmiGui {

class HMIGUI_EXPORT Environment : public QObject
{
    Q_OBJECT
public:
    static Environment* instance();

    QString themesFolder() const;
    void setThemesFolder(const QString &value);

private:
    explicit Environment(QObject *parent);

    QString m_themesFolder;

};

}
#endif // ENVIRONMENT

