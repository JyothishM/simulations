#-------------------------------------------------
#
# Project created by QtCreator 2012-09-19T23:17:57
#
#-------------------------------------------------

QT       -= gui

TARGET = simulation_utilities
TEMPLATE = lib

DEFINES += SIMULATION_UTILITIES_LIBRARY

SOURCES += \
    csvwriter.cpp \
    csvreader.cpp

HEADERS +=\
        simulation_utilities_global.h \
    csvwriter.h \
    CSVcommon.h \
    csvreader.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEC25DDDD
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = simulation_utilities.dll
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
