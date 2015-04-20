#ifndef HMIGUI_GLOBAL
#define HMIGUI_GLOBAL

#include <QtCore/QtGlobal>

#if defined(HMIGUI_LIBRARY)
#   define HMIGUI_EXPORT Q_DECL_EXPORT
#else
#   define HMIGUI_EXPORT Q_DECL_IMPORT
#endif // HMIGUI_LIBRARY

#endif // HMIGUI_GLOBAL
