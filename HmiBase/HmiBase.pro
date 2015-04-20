TEMPLATE = lib
TARGET = HmiBase
QT += quick

# Dependencies
INCLUDEPATH += \
    ../HmiGui \
    ../HmiStateMachine

LIBS += -L$$buildLibDir -lHmiGui -lHmiStateMachine


# Installation path
DESTDIR = $$buildLibDir
target.path = $$buildLibDir
INSTALLS += target


# Environment variables for source code
DEFINES += HMIBASE_LIBRARY


HEADERS += \
    ihmimodulecreator.h \
    hmibase_global.h \
    hmimodule.h \
    hmimoduleid.h \
    mainapplication.h \
    ihmivariables.h \
    modulecontroller.h

SOURCES += \
    ihmimodulecreator.cpp \
    hmimodule.cpp \
    mainapplication.cpp \
    ihmivariables.cpp \
    modulecontroller.cpp
