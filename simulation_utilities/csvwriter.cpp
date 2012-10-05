#include "csvwriter.h"
#include <QTextStream>
#include <QDebug>

CSVwriter::CSVwriter()
{
}
bool CSVwriter::WriteCSV(QIODevice * device, CSVTable &table,QString saporator,QString stringEnd)
{
    QTextStream stream(device);
    foreach(QVariantList line,table)
    {
        foreach(QVariant cell,line)
        {
            stream << stringEnd << cell.toString() << stringEnd << saporator;
        }
        stream << "\n";
    }
    return true;
}
