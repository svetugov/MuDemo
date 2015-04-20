#include "stateguisupporter.h"

using namespace HmiGui;

StateGuiSupporter::StateGuiSupporter(QObject *parent) :
    QObject(parent)
{
}

StateGuiSupporter* StateGuiSupporter::instance()
{
    return m_stateGuiSupporterInstance;
}

StateGuiSupporter* StateGuiSupporter::m_stateGuiSupporterInstance = 0;
