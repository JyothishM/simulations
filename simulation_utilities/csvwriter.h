#ifndef CSVWRITER_H
#define CSVWRITER_H

#include "simulation_utilities_global.h"
#include "CSVcommon.h"
#include <QIODevice>


class SIMULATION_UTILITIESSHARED_EXPORT CSVwriter
{
public:
    CSVwriter();
    static bool WriteCSV(QIODevice* device,CSVTable& table,QString saporator=",",QString stringEnd="");
};

#endif // CSVWRITER_H
