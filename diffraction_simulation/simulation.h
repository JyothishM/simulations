#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include "fhdiffraction.h"

class Beam;
class Apperture;

class Simulation : public QObject
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

    Simulation(BeamType beamType,
               AppertureType AppType,
               double screenXmin,double screenXmax,double screenXStep,
               QString filename,
               double xMin=-1e-2,double xMax=1e-2,
               double yMin=-1e-2,double yMax=1e-2,
               double tolerance=2e-6,
               QObject* parent=0);
    Simulation(QString strBeamType,
               QString strAppType,
               double screenXmin,double screenXmax,double screenXStep,
               QString filename,
               double xMin=-1e-2,double xMax=1e-2,
               double yMin=-1e-2,double yMax=1e-2,
               double tolerance=2e-6,
               QObject* parent=0);
    ~Simulation();
    int Start();
private:
    void Init(BeamType beamType,
              AppertureType AppType,
              double screenXmin,double screenXmax,double screenXStep,
              QString filename,
              double xMin,double xMax,
              double yMin,double yMax,
              double tolerance);
    Beam* CreateBeam(BeamType beamType);
    Apperture* CreateApperture(AppertureType AppType);
    bool Verify(Beam* beam,Apperture* apperture);
    BeamType FindBeamType(QString strBeamtype);
    AppertureType FindAppertureType(QString strAppType);


    FHDiffraction* mFHdiff;
    AppertureType mAppType;
    BeamType mBeamType;
    double mScreenXmin,mScreenXmax;
    double mScreenXStep;
    QString mFileName;
};

#endif // SIMULATION_H
