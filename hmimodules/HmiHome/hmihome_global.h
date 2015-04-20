#ifndef HMIHOME_GLOBAL_H
#define HMIHOME_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HMIHOME_PLUGIN)
#  define HMIHOME_EXPORT Q_DECL_EXPORT
#else
#  define HMIHOME_EXPORT Q_DECL_IMPORT
#endif

#endif // HMIHOME_GLOBAL_H
