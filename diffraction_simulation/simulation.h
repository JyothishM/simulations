#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QVariantList>
#include "fhdiffraction.h"

class Beam;
class Apperture;
typedef QList<QVariantList> CSVTable;

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
               double lamda, // wavelength
               double z,
               double screenXmin,double screenXmax,double screenXStep,
               QString filename,
               double xMin=-1e-2,double xMax=1e-2,
               double yMin=-1e-2,double yMax=1e-2,
               double tolerance=2e-6,
               QObject* parent=0);
    Simulation(QString strBeamType,
               QString strAppType,
               double lamda, // wavelength
               double z,
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
              double lamda, // wavelength
              double z,
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
    void DoSimulation(CSVTable& table);
    void WriteToFile(CSVTable& table);


    FHDiffraction* mFHdiff;
    AppertureType mAppType;
    BeamType mBeamType;
    double mScreenXmin,mScreenXmax;
    double mScreenXStep;
    QString mFileName;
};

#endif // SIMULATION_H
