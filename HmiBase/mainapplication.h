#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QGuiApplication>
#include <QQuickView>

#include "hmibase_global.h"
#include "hmimoduleid.h"

namespace HmiGui {
class ViewManager;
class ThemeManager;
}
namespace HmiStateMachine {
class StateMachine;
}

namespace HmiBase {
class HmiModule;
class IHmiVariables;

class HMIBASE_EXPORT MainApplication : public QGuiApplication
{
    Q_OBJECT
public:
    explicit MainApplication(int &argc, char **argv, IHmiVariables *hmiVariables);
    virtual ~MainApplication() {}


private:
    void loadHmiModules();
    void launchStateMachine();

    IHmiVariables *m_hmiVariables;
    QQuickView m_quickView;
    HmiGui::ViewManager *m_viewManager;
    HmiGui::ThemeManager *m_themeManager;
    QHash<HmiModuleId, HmiModule*> m_hmiModules;
};

}
#endif // MAINAPPLICATION_H
