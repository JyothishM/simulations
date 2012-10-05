#ifndef SIMULATION_CORETEST_H
#define SIMULATION_CORETEST_H

#include <QDebug>
#include "abstractsimulation.h"
#include "abstractsimulationengine.h"

class TestSimulation : public AbstractSimulation
{
    Q_OBJECT
public:
    explicit TestSimulation(AbstractSimulationEngine* engine,int SimId,QObject* parent=0)
        : AbstractSimulation(engine,SimId,parent)
    {

    }
    virtual ~TestSimulation()
    {

    }
    virtual bool Start()
    {
        qDebug() << "start of simulation.";
        qDebug() << QString(" %0 = %1").arg("field1").arg(GetSimulationEngine()->GetValue("field1",GetSimId()));
    }
};

class TestSimEngine : public AbstractSimulationEngine
{
    Q_OBJECT
public:
    explicit TestSimEngine(QObject *parent = 0)
        : AbstractSimulationEngine(parent)
    {

    }
    virtual ~TestSimEngine()
    {

    }
    virtual AbstractSimulation* CreateSimulation(QString type,int id)
    {
        return new TestSimulation(this,id);
    }
    virtual void onAllSimulationEnd()
    {
        qDebug() << "write to file here..";
    }
};




void TestSimulationCore();

#endif // SIMULATION_CORETEST_H
