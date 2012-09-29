#include "csvwriter.h"
#include <QTextStream>
#include <QDebug>

CSVwriter::CSVwriter()
{
}
bool CSVwriter::WriteCSV(QIODevice * device, CSVTable &table,QString saporator,QString bSaporator)
{
    QTextStream stream(device);
    foreach(QVariantList line,table)
    {
        foreach(QVariant cell,line)
        {
            stream << bSaporator << cell.toString() << bSaporator << saporator;
        }
        stream << "\n";
    }
    return true;
}
