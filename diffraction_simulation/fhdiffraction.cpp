#include "fhdiffraction.h"
#include "beam.h"
#include "apperture.h"
#include "basicmath.h"
#include "integrator.h"
#include <QDebug>

using namespace SimMath;
using namespace SimMath::BasicMath;

FHDiffraction* FHDiffraction::mCurObj=0;

FHDiffraction::FHDiffraction(QObject *parent)
    : QObject(parent)
{
    mZ = 1;
    mLamda = 650e-9;
    mBeam = 0;
    mApperture = 0;
    mCurX = 0;
    mCurY = 0;
    mBeam = 0;

    mXmin = -3e-2;   mXmax = 3e-2;
    mYmin = -3e-2;   mYmax = 3e-2;
    mTol = 2e-6;
}
FHDiffraction::~FHDiffraction()
{
    if(mBeam)
        delete mBeam;
    if(mApperture)
        delete mApperture;
}
void FHDiffraction::SetZ(double z)
{
    mZ = z;
}
double FHDiffraction::GetZ()
{
    return mZ;
}
void FHDiffraction::SetLamda(double lamda)
{
    mLamda = lamda;
}
double FHDiffraction::GetLamda()
{
    return mLamda;
}
void FHDiffraction::SetBeam(Beam* beam)
{
    mBeam = beam;
}
Beam* FHDiffraction::GetBeam()
{
    return mBeam;
}
void FHDiffraction::SetApperture(Apperture* apperture)
{
    mApperture = apperture;
}
Apperture* FHDiffraction::GetApperture()
{
    return mApperture;
}
bool FHDiffraction::Init()
{
    if(!mBeam || !mApperture)
        return false;

    mK = 2*Pi/mLamda;
    mConst1 = Expi(mK*mZ) / i(mLamda*mZ);
    mConst2 = i(mK/(2*mZ));
    mConst3 = i(2*Pi/(mLamda*mZ));

    qDebug() <<"lamda = " << mLamda << ", K=" << mK;
    qDebug() << "Init: const1,const2,const3 =" << mConst1.ToString() << mConst2.ToString() << mConst3.ToString();

    return true;
}
double FHDiffraction::IntensityAt(double x,double y)
{
    if(!mBeam)
        return 0;
    if(!mApperture)
        return 1;
    mCurX = x;
    mCurY = y;
    mCurObj = this;
    SimComplex cAmpl = Integrator::SurfIntegral(&FHDiffraction::IntegrantFroCur,
                                                     mXmin,mXmax,
                                                     mYmin,mYmax,
                                                     mTol);


    qDebug() << QString("Intensity at %0,%1 = %2").arg(x).arg(y).arg(cAmpl.ToString());
    double AmplMod = cAmpl.Mod();
    return AmplMod*AmplMod;
}
void FHDiffraction::SetEvaluationConfig(double xMin,double xMax,double yMin,double yMax,double tol)
{
    mXmin = xMin;   mXmax = xMax;
    mYmin = yMin;   mYmax = yMax;
    mTol = tol;
}

//private
SimMath::SimComplex FHDiffraction::Integrant(double chi,double ita)
{
    SimComplex value;
    if(!mBeam || !mApperture)
        return value;

    value = mBeam->I(chi,ita) * mApperture->U(chi,ita) * Exp(mConst3 * (mCurX*chi + mCurY*ita));
    return value;
}
SimMath::SimComplex FHDiffraction::IntegrantFroCur(double chi,double ita)
{
    return mCurObj->Integrant(chi,ita);
}
