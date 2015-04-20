TEMPLATE = lib
QT += qml
CONFIG += plugin

INCLUDEPATH += ../HmiBase
INCLUDEPATH += ../HmiStateMachine
LIBS += $$buildLibDir/HmiBase.lib
LIBS += $$buildLibDir/HmiStateMachine.lib

DLLDESTDIR = $$buildRootDir/hmimodules
DESTDIR = $$buildRootDir/hmimodules
