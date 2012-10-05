#ifndef FHSIMULATIONENGINE_H
#define FHSIMULATIONENGINE_H

#include "abstractsimulationengine.h"

class FHsimulationEngine : public AbstractSimulationEngine
{
    Q_OBJECT
public:
    explicit FHsimulationEngine(QObject *parent = 0);
    virtual ~FHsimulationEngine();
    virtual AbstractSimulation* CreateSimulation(QString type,int id);
protected slots:
    virtual void onAllSimulationEnd();
};

#endif // FHSIMULATIONENGINE_H
