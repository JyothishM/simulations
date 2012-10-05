#-------------------------------------------------
#
# Project created by QtCreator 2012-09-30T17:07:55
#
#-------------------------------------------------

QT       -= gui

TARGET = simulation_core
TEMPLATE = lib

DEFINES += SIMULATION_CORE_LIBRARY

SOURCES += abstractsimulation.cpp \
    abstractsimulationengine.cpp

HEADERS += abstractsimulation.h\
        simulation_core_global.h \
    abstractsimulationengine.h \
    simulation_consts.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEC981500
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = simulation_core.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BIN/simulation_utilities/debug/release/ -lsimulation_utilities
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BIN/simulation_utilities/debug/debug/ -lsimulation_utilities
else:symbian: LIBS += -lsimulation_utilities
else:unix: LIBS += -L$$PWD/../BIN/simulation_utilities/debug/ -lsimulation_utilities

INCLUDEPATH += $$PWD/../simulation_utilities
DEPENDPATH += $$PWD/../simulation_utilities
