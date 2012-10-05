#include <QtCore/QCoreApplication>

#include "mathtest.h"
#include "simulation_coreTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //MathTest();
    TestSimulationCore();

    return a.exec();
}
