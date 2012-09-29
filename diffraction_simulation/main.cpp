#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QObject>
#include "simulation.h"

#define REQD_NO_OF_ARGU 7
#define MAX_NO_OF_ARGU 12

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc<REQD_NO_OF_ARGU)
    {
        qDebug() << QObject::tr("Less number of arguments, at least %0 no. of arguments needed, process terminated.").arg(REQD_NO_OF_ARGU);
        return -1;
    }
    else if(argc>MAX_NO_OF_ARGU)
    {
        qDebug() << QObject::tr("More number of arguments, only %0 no. of arguments needed").arg(MAX_NO_OF_ARGU);
    }

    bool ok=false;

    QString strBeamType = argv[1];
    QString strAppertureType = argv[2];
    QString strd = QString(argv[3]);
    double dScreenXmin = strd.toDouble(&ok);
    if(!ok)
    {
        qDebug() << QObject::tr("Could not convert argument 3 to double, process terminated.") << strd;
        return -1;
    }
    double dScreenXmax = QString(argv[4]).toDouble(&ok);
    if(!ok)
    {
        qDebug() << QObject::tr("Could not convert argument 4 to double, process terminated.");
        return -1;
    }
    double dTolerance = QString(argv[5]).toDouble(&ok);
    if(!ok)
    {
        qDebug() << QObject::tr("Could not convert argument 5 to double, process terminated.");
        return -1;
    }
    QString strFilename = argv[6];


    Simulation s(strBeamType,
                 strAppertureType,
                 dScreenXmin,dScreenXmax,
                 dTolerance,
                 strFilename);
    return s.Start();
    //return a.exec();
}
