#ifndef CSVWRITER_H
#define CSVWRITER_H

#include "simulation_utilities_global.h"
#include <QIODevice>
#include <QVariant>

typedef QList<QVariantList> CSVTable;

class SIMULATION_UTILITIESSHARED_EXPORT CSVwriter
{
public:
    CSVwriter();
    static bool WriteCSV(QIODevice * device,CSVTable& table,QString saporator=",",QString bSaporator="");
};

#endif // CSVWRITER_H
