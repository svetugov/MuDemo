TEMPLATE = lib
TARGET = HmiGui
QT += quick

# Dependencies
INCLUDEPATH += $$PWD

# Installation path
DESTDIR = $$buildLibDir
target.path = $$buildLibDir
INSTALLS += target

# Environment variables for source code
DEFINES += BUILD_ROOT_DIR=\\\"$$buildRootDir\\\"
DEFINES += HMIGUI_LIBRARY


HEADERS += \
    view.h \
    viewid.h \
    viewloader.h \
    viewmanager.h \
    hmigui_global.h \
    stateguisupporter.h \
    painter.h \
    thememanager.h \
    theme.h \
    themescollection.h \
    tools.h \
    environment.h

SOURCES += \
    viewloader.cpp \
    viewmanager.cpp \
    stateguisupporter.cpp \
    painter.cpp \
    thememanager.cpp \
    tools.cpp \
    environment.cpp

DISTFILES +=
