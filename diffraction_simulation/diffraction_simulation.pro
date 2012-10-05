#-------------------------------------------------
#
# Project created by QtCreator 2012-09-19T23:16:41
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = diffraction_simulation
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    apperture.cpp \
    beam.cpp \
    fhdiffraction.cpp \
    fhsimulation.cpp \
    fhsimulationengine.cpp


HEADERS += \
    apperture.h \
    beam.h \
    fhdiffraction.h \
    fhsimulation.h \
    fhsimulationengine.h \
    FHsimulation_consts.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BIN/simulation_math/debug/release/ -lsimulation_math
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BIN/simulation_math/debug/debug/ -lsimulation_math
else:symbian: LIBS += -lsimulation_math
else:unix: LIBS += -L$$PWD/../BIN/simulation_math/debug/ -lsimulation_math

INCLUDEPATH += $$PWD/../simulation_math
DEPENDPATH += $$PWD/../simulation_math

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BIN/simulation_utilities/debug/release/ -lsimulation_utilities
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BIN/simulation_utilities/debug/debug/ -lsimulation_utilities
else:symbian: LIBS += -lsimulation_utilities
else:unix: LIBS += -L$$PWD/../BIN/simulation_utilities/debug/ -lsimulation_utilities

INCLUDEPATH += $$PWD/../simulation_utilities
DEPENDPATH += $$PWD/../simulation_utilities

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BIN/simulation_core/debug/release/ -lsimulation_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BIN/simulation_core/debug/debug/ -lsimulation_core
else:symbian: LIBS += -lsimulation_core
else:unix: LIBS += -L$$PWD/../BIN/simulation_core/debug/ -lsimulation_core

INCLUDEPATH += $$PWD/../simulation_core
DEPENDPATH += $$PWD/../simulation_core
