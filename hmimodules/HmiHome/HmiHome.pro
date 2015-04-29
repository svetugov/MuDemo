TARGET = HmiHome
DEFINES += HMIHOME_PLUGIN


# Common rules for all hmi modules
include(../hmimodules.pri)
INCLUDEPATH += ../../HmiBase
INCLUDEPATH += ../../HmiStateMachine
INCLUDEPATH += ../../HmiGui


# Installation path
qml.files = qml/*
qml.path = $$buildRootDir/qml/$$TARGET
INSTALLS += qml


HEADERS += \
    hmihome_global.h \
    homemain.h \
    homecreator.h \
    homecontroller.h \
    hometransitions.h

SOURCES += \
    homemain.cpp \
    homecontroller.cpp


DISTFILES += \
    qml/HomeFameHall.qml \
    qml/HomeMain.qml \
    qml/viewDescriptor.json

