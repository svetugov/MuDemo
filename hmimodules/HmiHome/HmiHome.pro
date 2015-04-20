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

QML_FILES += \
    viewDescriptor.json \
    qml/HomeMain.qml \
    qml/HomeGrid.qml

qml.files = $$QML_FILES

OTHER_FILES += \
        $$QML_FILES

