TARGET = HmiHome
DEFINES += HMIHOME_PLUGIN


# Common rules for all hmi modules
include(../hmimodules.pri)
INCLUDEPATH += ../../HmiBase
INCLUDEPATH += ../../HmiStateMachine
INCLUDEPATH += ../../HmiGui


# Installation path
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

qml.files = qml/*

OTHER_FILES += \
        $$QML_FILES

DISTFILES += \
    qml/HomeFameHall.qml

