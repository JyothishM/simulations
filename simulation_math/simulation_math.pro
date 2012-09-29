#-------------------------------------------------
#
# Project created by QtCreator 2012-09-19T23:18:44
#
#-------------------------------------------------

QT       -= gui

TARGET = simulation_math
TEMPLATE = lib

DEFINES += SIMULATION_MATH_LIBRARY

SOURCES += \
    integrator.cpp \
    BasicMath/simcomplex.cpp \
    basicmath.cpp

HEADERS +=\
        simulation_math_global.h \
    integrator.h \
    BasicMath/simcomplex.h \
    BasicMath/MathConsts.h \
    basicmath.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE30B79B9
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = simulation_math.dll
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
