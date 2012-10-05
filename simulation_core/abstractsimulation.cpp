#include "abstractsimulation.h"


AbstractSimulation::AbstractSimulation(AbstractSimulationEngine* engine,int SimId, QObject *parent)
    : QObject(parent)
{
    mSimId = SimId;
    mEngine = engine;
}
AbstractSimulation::~AbstractSimulation()
{
}
int AbstractSimulation::GetSimId()
{
    return mSimId;
}
AbstractSimulationEngine* AbstractSimulation::GetSimulationEngine()
{
    return mEngine;
}
void AbstractSimulation::EmitFinished()
{
    emit Finished(this);
}
