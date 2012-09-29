#include "simulation.h"
#include "beam.h"
#include "apperture.h"
#include "csvwriter.h"
#include <QDebug>
#include <QObject>
#include <QFile>

Simulation::Simulation(BeamType beamType,
                       AppertureType AppType,
                       double screenXmin, double screenXmax,double screenXStep,
                       QString filename,
                       double xMin,double xMax,
                       double yMin,double yMax,
                       double tolerance,
                       QObject *parent)
    : QObject(parent)
{
    Init(beamType,
         AppType,
         screenXmin,screenXmax,screenXStep,
         filename,xMin,
         xMax,yMin,
         yMax,
         tolerance);
}
Simulation::Simulation(QString strBeamType,
                       QString strAppType,
                       double screenXmin, double screenXmax,double screenXStep,
                       QString filename,
                       double xMin,double xMax,
                       double yMin,double yMax,
                       double tolerance,
                       QObject *parent)
    : QObject(parent)
{
    Init(FindBeamType(strBeamType),
         FindAppertureType(strAppType),
         screenXmin,screenXmax,screenXStep,
         filename,xMin,
         xMax,yMin,
         yMax,
         tolerance);
}
Simulation::~Simulation()
{

}
int Simulation::Start()
{
    qDebug() << tr("Initializing simulation..!");
    Beam* beam = CreateBeam(mBeamType);
    Apperture* apperture = CreateApperture(mAppType);
    if(!Verify(beam,apperture))
    {
        qCritical() << tr("Ending simulation..!");
        return -1;
    }
    mFHdiff->SetBeam(beam);
    mFHdiff->SetApperture(apperture);
    mFHdiff->Init();

//    double y = 0;
//    for(double x=mScreenXmin; x<= mScreenXmax; x+=mScreenXStep)
//    {
//        qDebug() << mFHdiff->IntensityAt(x,y);
//    }


    /////////////////////////////////////////////////////////////

    CSVTable table;
    QVariantList header;
    header << "x" << "Intensity";
    table << header;

    double y = 0;
    int NofEval = (mScreenXmax-mScreenXmin)/mScreenXStep;
    int i=1;
    for(double x=mScreenXmin; x<= mScreenXmax; x+=mScreenXStep)
    {
        double intensity = mFHdiff->IntensityAt(x,y);
        QVariantList line;
        line << x << intensity;
        table << line;
        qDebug() << tr("Intensity at x =%0, %1").arg(x).arg(intensity);
        qDebug() << tr("%0 % of simulation completed.").arg(((float)i)*100/NofEval);
        i++;
    }


    QFile file(mFileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << tr("Output file %0 is succesfully opened").arg(mFileName);
        bool succes = CSVwriter::WriteCSV(&file,table);
        qDebug() << tr("Writing succes =%0").arg(succes);
        file.close();
        qDebug() << tr("Output file %0 is closed.").arg(mFileName);
    }
    else
    {
        qDebug() << tr("Output file %0 is could not be opened").arg(mFileName);
    }

    return 0;
}
// private
void Simulation::Init(BeamType beamType,
                      AppertureType AppType,
                      double screenXmin, double screenXmax,double screenXStep,
                      QString filename,double xMin,
                      double xMax, double yMin,
                      double yMax,
                      double tolerance)
{
    mBeamType = beamType;
    mAppType = AppType;
    mScreenXmin = screenXmin;
    mScreenXmax = screenXmax;
    mScreenXStep = screenXStep;
    mFileName = filename;
    mFHdiff = new FHDiffraction(this);
    mFHdiff->SetEvaluationConfig(xMin,xMax,
                                 yMin,yMax,
                                 tolerance);
}
Beam* Simulation::CreateBeam(BeamType beamType)
{
    Beam* beam=0;
    switch(mBeamType)
    {
    case RECTANGLUAR:
        beam = new RectBeam();
        break;
    }
    return beam;
}
Apperture* Simulation::CreateApperture(AppertureType AppType)
{
    Apperture* apperture=0;
    switch(mAppType)
    {
    case SINGLE_SLIT:
        apperture = new SingleSlit();
        break;
    }
    return apperture;
}
bool Simulation::Verify(Beam* beam,Apperture* apperture)
{
    bool succes=true;
    qDebug() << tr("Checking beam");
    if(!beam)
    {
        qCritical() << tr("Error :The given beam type is not available.");
        succes = false;
    }
    qDebug() << tr("Checking apperture");
    if(!apperture)
    {
        qCritical() << tr("Error :The given apperture type is not available.");
        succes = false;
    }
    if(succes)
        qDebug() << tr("Beam and Apperture types are verified..!");
    return succes;
}
Simulation::BeamType Simulation::FindBeamType(QString strBeamtype)
{
    BeamType beamtype;
    if(!strBeamtype.compare("RECTANGUALR",Qt::CaseInsensitive))
        beamtype = RECTANGLUAR;
    else if(!strBeamtype.compare("GAUSSIAN",Qt::CaseInsensitive))
        beamtype = GAUSSIAN;
    return beamtype;
}
Simulation::AppertureType Simulation::FindAppertureType(QString strAppType)
{
    AppertureType appType;
    if(!strAppType.compare("SINGLE_SLIT",Qt::CaseInsensitive))
        appType = SINGLE_SLIT;
    else if(!strAppType.compare("DOUBLE_SLIT",Qt::CaseInsensitive))
        appType = DOUBLE_SLIT;
    else if(!strAppType.compare("CIRCULAR_APPERTURE",Qt::CaseInsensitive))
        appType = CIRCULAR_APPERTURE;
    else if(!strAppType.compare("WIRE_MESH",Qt::CaseInsensitive))
        appType = WIRE_MESH;
    else if(!strAppType.compare("SINGLE_WIRE",Qt::CaseInsensitive))
        appType = SINGLE_WIRE;
    else if(!strAppType.compare("CROSS_WIRE",Qt::CaseInsensitive))
        appType = CROSS_WIRE;
    return appType;
}
