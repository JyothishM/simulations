#include "fhsimulation.h"
#include "abstractsimulationengine.h"
#include "FHsimulation_consts.h"
#include "beam.h"
#include "apperture.h"
#include "csvwriter.h"
#include <QDebug>
#include <QObject>
#include <QFile>

FHsimulation::FHsimulation(AbstractSimulationEngine* engine,
                           int SimId,
                           QObject* parent)
    : AbstractSimulation(engine,SimId,parent)
{

}
FHsimulation::~FHsimulation()
{

}
bool FHsimulation::Start()
{
    qDebug() << tr("Initializing simulation..!");
    bool succes = Init();
    if(!succes)
    {
        qDebug() << tr("Simulation initialization failed.");
    }
    else
    {
        Beam* beam = CreateBeam(mBeamType);
        Apperture* apperture = CreateApperture(mAppType);
        if(!Verify(beam,apperture))
        {
            qCritical() << tr("Ending simulation..!");
            return false;
        }
        mFHdiff->SetBeam(beam);
        mFHdiff->SetApperture(apperture);
        mFHdiff->Init();

        CSVTable table;
        DoSimulation(table);
        WriteToFile(table);
    }

    return succes;
}
// private
bool FHsimulation::Init()
{
    qDebug() << tr("Initializing..");
    AbstractSimulationEngine* engine = GetSimulationEngine();
    if(!engine)
    {
        qDebug() << tr("Simulation engine is not set, returning from simulation.");
        return false;
    }

    int simid = GetSimId();
    mBeamType = FindBeamType(engine->GetValue(STR_BEAMTYPE,simid));
    mAppType = FindAppertureType(engine->GetValue(STR_APPTYPE,simid));

    bool ok=false;
    mScreenXmin = engine->GetValue(STR_SCREEN_XMIN,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_SCREEN_XMIN);
        return false;
    }

    mScreenXmax = engine->GetValue(STR_SCREEN_XMAX,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_SCREEN_XMAX);
        return false;
    }

    mScreenXStep = engine->GetValue(STR_SCREEN_XSTEP,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_SCREEN_XSTEP);
        return false;
    }


    double lamda = engine->GetValue(STR_LAMDA,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_LAMDA);
        return false;
    }

    double z = engine->GetValue(STR_Z,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_Z);
        return false;
    }

    double xMin = engine->GetValue(STR_INT_XMIN,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_INT_XMIN);
        return false;
    }

    double xMax = engine->GetValue(STR_INT_XMAX,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_INT_XMAX);
        return false;
    }

    double yMin = engine->GetValue(STR_INT_YMIN,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_INT_YMIN);
        return false;
    }

    double yMax = engine->GetValue(STR_INT_YMAX,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_INT_YMAX);
        return false;
    }

    double tolerance = engine->GetValue(STR_INT_TOL,simid).toDouble(&ok);
    if(!ok)
    {
        qDebug() << tr("Could not convert %0 to double").arg(STR_INT_TOL);
        return false;
    }

    mFileName = engine->GetValue(STR_FILENAME,simid);
    if(mFileName.isEmpty())
    {
        qDebug() << tr("The filename is empty.");
        return false;
    }

    mFHdiff = new FHDiffraction(this);
    mFHdiff->SetEvaluationConfig(xMin,xMax,
                                 yMin,yMax,
                                 tolerance);
    mFHdiff->SetLamda(lamda);
    mFHdiff->SetZ(z);
    return true;
}
Beam* FHsimulation::CreateBeam(BeamType beamType)
{
    Beam* beam=0;

    qDebug() << "BeamType" << beamType;

    switch(beamType)
    {
    case RECTANGLUAR:
        beam = new RectBeam();
        break;
    }
    return beam;
}
Apperture* FHsimulation::CreateApperture(AppertureType AppType)
{
    Apperture* apperture=0;
    switch(AppType)
    {
    case SINGLE_SLIT:
        apperture = new SingleSlit();
        break;
    case DOUBLE_SLIT:
        apperture = new DoubleSlit();
        break;
    case CIRCULAR_APPERTURE:
        apperture = new CircularApperture();
        break;
    case WIRE_MESH:
        apperture = new WireMesh();
        break;
    case SINGLE_WIRE:
        apperture = new SingleWire();
        break;
    case CROSS_WIRE:
        apperture = new CrossWire();
        break;
    }
    return apperture;
}
bool FHsimulation::Verify(Beam* beam,Apperture* apperture)
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
FHsimulation::BeamType FHsimulation::FindBeamType(QString strBeamtype)
{

    BeamType beamtype;
    if(!strBeamtype.compare("RECTANGULAR",Qt::CaseInsensitive))
        beamtype = RECTANGLUAR;
    else if(!strBeamtype.compare("GAUSSIAN",Qt::CaseInsensitive))
        beamtype = GAUSSIAN;

    qDebug() << "strBeamtype =" << strBeamtype << beamtype;
    return beamtype;
}
FHsimulation::AppertureType FHsimulation::FindAppertureType(QString strAppType)
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
void FHsimulation::DoSimulation(CSVTable& table)
{
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
}
void FHsimulation::WriteToFile(CSVTable& table)
{
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
}

