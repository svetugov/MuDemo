#ifndef HMIBASE_GLOBAL
#define HMIBASE_GLOBAL

#include <QtCore/QtGlobal>

#if defined(HMIBASE_LIBRARY)
    #define HMIBASE_EXPORT Q_DECL_EXPORT
#else
    #define HMIBASE_EXPORT Q_DECL_IMPORT
#endif // HMIBASE_LIBRARY

#endif // HMIBASE_GLOBAL

