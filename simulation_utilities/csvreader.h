#ifndef CSVREADER_H
#define CSVREADER_H

#include "simulation_utilities_global.h"
#include "CSVcommon.h"
#include <QIODevice>


// known bug: saporator within two stringEnds will not be skiped

class SIMULATION_UTILITIESSHARED_EXPORT CSVreader
{
public:
    CSVreader();
    static bool ReadCSV(QIODevice* device,CSVTable& table,QString saporator=",",QString stringEnd="");
};

#endif // CSVREADER_H
