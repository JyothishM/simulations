#include "fhsimulationengine.h"
#include "fhsimulation.h"
#include <QDebug>

FHsimulationEngine::FHsimulationEngine(QObject *parent)
    : AbstractSimulationEngine(parent)
{

}
FHsimulationEngine::~FHsimulationEngine()
{

}
AbstractSimulation* FHsimulationEngine::CreateSimulation(QString type,int id)
{
    return new FHsimulation(this,id,this);  // type is imeterial.
}
void FHsimulationEngine::onAllSimulationEnd()
{
    qDebug() << tr("Simulation finished.");
}
