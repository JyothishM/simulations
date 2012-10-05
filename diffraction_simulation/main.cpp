#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QObject>
#include "fhsimulationengine.h"

#define REQD_NO_OF_ARGU 2
#define MAX_NO_OF_ARGU 2



bool CheckConstraints(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(CheckConstraints(argc,argv))
    {
        FHsimulationEngine SimEngine(0);

        QString filename = argv[1];

        if(!filename.isEmpty())
        {
            SimEngine.SetSettingsFile(filename);
            SimEngine.Start();
        }
        else
        {
            qDebug() << QObject::tr("The argument filename is empty");
            return -1;
        }
    }

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
