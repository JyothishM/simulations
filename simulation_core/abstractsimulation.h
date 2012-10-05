#ifndef ABSTRACTSIMULATION_H
#define ABSTRACTSIMULATION_H

#include "simulation_core_global.h"
#include <QObject>

class AbstractSimulationEngine;

class SIMULATION_CORESHARED_EXPORT AbstractSimulation : public QObject
{
    Q_OBJECT
public:
    explicit AbstractSimulation(AbstractSimulationEngine* engine,int SimId,QObject* parent=0);
    virtual ~AbstractSimulation();
    virtual bool Start()=0;
    int GetSimId();
    AbstractSimulationEngine* GetSimulationEngine();
signals:
    void Finished(AbstractSimulation* simln);
protected:
    void EmitFinished();
private:
    int mSimId;
    AbstractSimulationEngine* mEngine;
};

#endif // ABSTRACTSIMULATION_H
