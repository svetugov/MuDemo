TEMPLATE = lib
TARGET = HmiStateMachine


# Dependencies
INCLUDEPATH += $$srcRootDir/HmiGui
LIBS += $$buildLibDir/HmiGui.lib


# Installation path
DESTDIR = $$buildLibDir
target.path = $$buildLibDir
INSTALLS += target


# Environment variables for source code
DEFINES += HMISTATEMACHINE_LIBRARY


HEADERS += \
    state.h \
    hmistatemachine_global.h \
    stateid.h \
    statemachine.h \
    viewstate.h \
    event.h \
    conditionaltransition.h \
    eventualtransition.h \
    eventid.h \
    transitionrequestevent.h

SOURCES += \
    state.cpp \
    statemachine.cpp \
    viewstate.cpp \
    conditionaltransition.cpp \
    eventualtransition.cpp \
    transitionrequestevent.cpp
