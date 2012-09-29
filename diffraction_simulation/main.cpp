#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QObject>
#include "simulation.h"

#define REQD_NO_OF_ARGU 9
#define MAX_NO_OF_ARGU 14

struct SimulationSettings
{
    QString strBeamType;
    QString strAppType;
    double lamda; // wavelength
    double z;
    double screenXmin,screenXmax,screenXStep;
    QString filename;
    double xMin,xMax;
    double yMin,yMax;
    double tolerance;
};

bool CheckConstraints(int argc, char *argv[]);
bool FindValues(int argc, char *argv[],SimulationSettings& settings);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(!CheckConstraints(argc,argv))
    {
        qDebug() << QObject::tr("Simulation terminated...!");
        return -1;
    }

    SimulationSettings settings;
    if(!FindValues(argc,argv,settings))
    {
        qDebug() << QObject::tr("Simulation terminated...!");
        return -1;
    }

    Simulation s(settings.strBeamType,
                 settings.strAppType,
                 settings.lamda,
                 settings.z,
                 settings.screenXmin,settings.screenXmax,
                 settings.screenXStep,
                 settings.filename);
    return s.Start();
    //return a.exec();
}

bool CheckConstraints(int argc, char *argv[])
{
    bool succes = true;
    if(argc<REQD_NO_OF_ARGU)
    {
        qDebug() << QObject::tr("Less number of arguments, at least %0 no. of arguments needed, process terminated.").arg(REQD_NO_OF_ARGU);
        succes = false;
    }
    else if(argc>MAX_NO_OF_ARGU)
    {
        qDebug() << QObject::tr("More number of arguments, only %0 no. of arguments needed").arg(MAX_NO_OF_ARGU);
    }
    return succes;
}
bool FindValues(int argc, char *argv[],SimulationSettings& settings)
{
    bool ok=false;
    int i=1;
    settings.strBeamType = argv[i++];
    settings.strAppType = argv[i++];

    settings.lamda = QString(argv[i++]).toDouble(&ok);
    if(!ok)
    {
        qDebug() << QObject::tr("Could not convert argument %0 to double, process terminated.").arg(i-1);
        return false;
    }
    settings.z = QString(argv[i++]).toDouble(&ok);
    if(!ok)
    {
        qDebug() << QObject::tr("Could not convert argument %0 to double, process terminated.").arg(i-1);
        return false;
    }
    settings.screenXmin = QString(argv[i++]).toDouble(&ok);
    if(!ok)
    {
        qDebug() << QObject::tr("Could not convert argument %0 to double, process terminated.").arg(i-1);
        return false;
    }
    settings.screenXmax = QString(argv[i++]).toDouble(&ok);
    if(!ok)
    {
        qDebug() << QObject::tr("Could not convert argument %0 to double, process terminated.").arg(i-1);
        return false;
    }
    settings.screenXStep = QString(argv[i++]).toDouble(&ok);
    if(!ok)
    {
        qDebug() << QObject::tr("Could not convert argument %0 to double, process terminated.").arg(i-1);
        return false;
    }
    settings.filename = argv[i++];
    return true;
}
