TEMPLATE = lib
TARGET = HmiGui
QT += qml quick

# Dependencies
INCLUDEPATH += $$PWD

# Installation path
DESTDIR = $$buildLibDir
target.path = $$buildLibDir

import.files = imports/*
import.path = $$buildRootDir/imports
INSTALLS += target import

# Environment variables for source code
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
    environment.h \
    animationmanager.h \
    settings.h

SOURCES += \
    viewloader.cpp \
    viewmanager.cpp \
    stateguisupporter.cpp \
    painter.cpp \
    thememanager.cpp \
    tools.cpp \
    environment.cpp \
    animationmanager.cpp \
    settings.cpp

DISTFILES += \
    imports/HmiGui/Controls/AnimatedTransition.qml \
    imports/HmiGui/Controls/qmldir \
    AnimatedItem.qml \
    imports/HmiGui/Controls/AnimatedItem.qml \
    imports/HmiGui/Styles/Style.qml \
    imports/HmiGui/Styles/qmldir \
    imports/HmiGui/Controls/View.qml \
    imports/HmiGui/qmldir
