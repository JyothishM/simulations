#include "csvreader.h"
#include <QTextStream>
#include <QStringList>
#include <QDebug>

CSVreader::CSVreader()
{
}
bool CSVreader::ReadCSV(QIODevice* device,CSVTable& table,QString saporator,QString stringEnd)
{
    bool succes=false;

    // clearing current tables
    table.clear();

    QTextStream stream(device);
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        QStringList tokens = line.split(saporator);
        QVariantList tableline;
        foreach(QString token,tokens)
        {
            if(!stringEnd.isEmpty())
            {
                int strEndlen = stringEnd.length();
                if(token.startsWith(stringEnd))
                {
                    token = token.right(token.length()-strEndlen);
                }
                if(token.endsWith(stringEnd))
                {
                    token = token.left(token.length()-strEndlen);
                }
            }
            tableline.append(token);
        }
        table.append(tableline);
    }

    succes = true;

    return succes;
}
