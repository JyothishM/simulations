#ifndef FHSIMULATION_H
#define FHSIMULATION_H

#include <QObject>
#include <QVariantList>
#include "fhdiffraction.h"
#include "abstractsimulation.h"

class Beam;
class Apperture;
typedef QList<QVariantList> CSVTable;

class FHsimulation : public AbstractSimulation
{
    Q_OBJECT
public:
    enum BeamType
    {
        RECTANGLUAR,
        GAUSSIAN
    };
    enum AppertureType
    {
        SINGLE_SLIT,
        DOUBLE_SLIT,
        CIRCULAR_APPERTURE,
        WIRE_MESH,
        SINGLE_WIRE,
        CROSS_WIRE
    };

    FHsimulation(AbstractSimulationEngine* engine,int SimId,QObject *parent=0);
    ~FHsimulation();
    virtual bool Start();
private:
    bool Init();
    Beam* CreateBeam(BeamType beamType);
    Apperture* CreateApperture(AppertureType AppType);
    bool Verify(Beam* beam,Apperture* apperture);
    BeamType FindBeamType(QString strBeamtype);
    AppertureType FindAppertureType(QString strAppType);
    void DoSimulation(CSVTable& table);
    void WriteToFile(CSVTable& table);


    FHDiffraction* mFHdiff;
    AppertureType mAppType;
    BeamType mBeamType;
    double mScreenXmin,mScreenXmax;
    double mScreenXStep;
    QString mFileName;
};


#endif // FHSIMULATION_H
