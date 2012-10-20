#ifndef SIMULATION_CORE_GLOBAL_H
#define SIMULATION_CORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMULATION_CORE_LIBRARY)
#  define SIMULATION_CORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define SIMULATION_CORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SIMULATION_CORE_GLOBAL_H