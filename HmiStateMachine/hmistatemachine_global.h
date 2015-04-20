#ifndef HMISTATEMACHINE_GLOBAL
#define HMISTATEMACHINE_GLOBAL

#include <QtCore/QtGlobal>

#if defined(HMISTATEMACHINE_LIBRARY)
    #define HMISTATEMACHINE_EXPORT Q_DECL_EXPORT
#else
    #define HMISTATEMACHINE_EXPORT Q_DECL_IMPORT
#endif // HMISTATEMACHINE_LIBRARY

#endif // HMISTATEMACHINE_GLOBAL

