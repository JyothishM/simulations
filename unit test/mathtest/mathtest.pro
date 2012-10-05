#-------------------------------------------------
#
# Project created by QtCreator 2012-09-27T14:12:26
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = mathtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    simulation_coreTest.cpp



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../BIN/simulation_math/debug/release/ -lsimulation_math
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../BIN/simulation_math/debug/debug/ -lsimulation_math
else:symbian: LIBS += -lsimulation_math
else:unix: LIBS += -L$$PWD/../../BIN/simulation_math/debug/ -lsimulation_math

INCLUDEPATH += $$PWD/../../simulation_math
DEPENDPATH += $$PWD/../../simulation_math

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../BIN/simulation_utilities/debug/release/ -lsimulation_utilities
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../BIN/simulation_utilities/debug/debug/ -lsimulation_utilities
else:symbian: LIBS += -lsimulation_utilities
else:unix: LIBS += -L$$PWD/../../BIN/simulation_utilities/debug/ -lsimulation_utilities

INCLUDEPATH += $$PWD/../../simulation_utilities
DEPENDPATH += $$PWD/../../simulation_utilities

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../BIN/simulation_core/debug/release/ -lsimulation_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../BIN/simulation_core/debug/debug/ -lsimulation_core
else:symbian: LIBS += -lsimulation_core
else:unix: LIBS += -L$$PWD/../../BIN/simulation_core/debug/ -lsimulation_core

INCLUDEPATH += $$PWD/../../simulation_core
DEPENDPATH += $$PWD/../../simulation_core

HEADERS += \
    simulation_coreTest.h \
    mathtest.h
