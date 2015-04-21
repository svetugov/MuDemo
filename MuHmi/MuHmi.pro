TEMPLATE = app
TARGET = MuHmi
QT += qml quick

# Environment variables for source code
DEFINES += BUILD_ROOT_DIR=\\\"$$buildRootDir\\\"

# Dependencies
INCLUDEPATH += $$srcRootDir/HmiBase
INCLUDEPATH += $$srcRootDir/HmiStateMachine
INCLUDEPATH += $$srcRootDir/HmiGui
LIBS += -L$$buildLibDir -lHmiBase -lHmiStateMachine

# Imports
QML2_IMPORT_PATH += "$$buildRootDir/imports"
# For QtCreator
QML_IMPORT_PATH += "$$srcRootDir/HmiGui/imports"

# Installation path
DESTDIR = $$buildBinDir
target.path = $$buildBinDir
qml.path = $$buildRootDir/qml
theme.path = $$buildRootDir/themes
INSTALLS += target qml theme


QML_FILES += \
    qml/main.qml

qml.files = $$QML_FILES
theme.files = themes/*

OTHER_FILES += \
    $$QML_FILES

SOURCES += main.cpp \
    muhmivariables.cpp

HEADERS += \
    muhmivariables.h
