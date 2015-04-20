#ifndef STATEGUISUPPORTER_H
#define STATEGUISUPPORTER_H

#include <QObject>

#include "hmigui_global.h"
#include "viewid.h"

namespace HmiGui {
/**
  StateGuiSupporter

  Provides API for state machine to operate views.
*/
class HMIGUI_EXPORT StateGuiSupporter : public QObject
{
    Q_OBJECT
public:
    static StateGuiSupporter* instance();

    virtual void showView(const ViewId &id) = 0;
    virtual void hideView(const ViewId &id) = 0;
    virtual ViewId topView() const = 0;

protected:
    static StateGuiSupporter* m_stateGuiSupporterInstance;
    StateGuiSupporter(QObject *parent);

};

}
#endif // STATEGUISUPPORTER_H
