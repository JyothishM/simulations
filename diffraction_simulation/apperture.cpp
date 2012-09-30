#include "apperture.h"
#include "qmath.h"
#include <QtGlobal>

Apperture::Apperture()
{
    mOrginPosX = 0;
    mOrginPosY = 0;
}
Apperture::~Apperture()
{
}
void Apperture::SetOrginPos(double x,double y)
{
    mOrginPosX = x;
    mOrginPosY = y;
}
double Apperture::GetOrginPosX()
{
    return mOrginPosX;
}
double Apperture::GetOrginPosY()
{
    return mOrginPosY;
}
void Apperture::SetAngle(double angle)
{
    mAngle = angle;
}
double Apperture::GetAngle()
{
    return mAngle;
}
///////////////////////SingleSlit///////////////////////////////////////
SingleSlit::SingleSlit()
{
    mSlitW = 50e-6;
    mSlitH = 3e-2;
}
SingleSlit::~SingleSlit()
{

}
double SingleSlit::U(double chi,double ita)
{
    if(qAbs(chi)<(mSlitW/2) &&
            qAbs(ita)<(mSlitH/2))
        return 1;
    return 0;
}
void SingleSlit::SetSlitW(double w)
{
    mSlitW = w;
}
double SingleSlit::GetSlitW()
{
    return mSlitW;
}
void SingleSlit::SetSlitH(double h)
{
    mSlitH = h;
}
double SingleSlit::GetSlitH()
{
    return mSlitH;
}
///////////////////////DoubleSlit///////////////////////////////////////
DoubleSlit::DoubleSlit()
{
    mSlitW = 50e-6;
    mSlitH = 3e-2;
    mSaporation = 50e-6;
}
DoubleSlit::~DoubleSlit()
{

}
double DoubleSlit::U(double chi,double ita)
{
    if(qAbs(chi)>(mSaporation/2)  && qAbs(chi)<(mSaporation/2 + mSlitW) &&
            qAbs(ita)<(mSlitH/2))
        return 1;
    return 0;
}
void DoubleSlit::SetSlitW(double w)
{
    mSlitW = w;
}
double DoubleSlit::GetSlitW()
{
    return mSlitW;
}
void DoubleSlit::SetSlitH(double h)
{
    mSlitH = h;
}
double DoubleSlit::GetSlitH()
{
    return mSlitH;
}
void DoubleSlit::SetSaporation(double d)
{
    mSaporation = d;
}
double DoubleSlit::GetSaporation()
{
    return mSaporation;
}
///////////////////////CircularApperture///////////////////////////////////////
CircularApperture::CircularApperture()
{
    mRad = 75e-6;
}
CircularApperture::~CircularApperture()
{

}
double CircularApperture::U(double chi,double ita)
{
    if((chi*chi+ita*ita) < (mRad*mRad))
        return 1;
    return 0;
}
void CircularApperture::SetRadius(double r)
{
    mRad = r;
}
double CircularApperture::GetRadius()
{
    return mRad;
}
///////////////////////WireMesh///////////////////////////////////////
WireMesh::WireMesh()
{
    mWireDia = 3e-5;
    mSaporation = 4e-5;
}
WireMesh::~WireMesh()
{

}
// fn to find modulo
inline double Modulo(double a,double b)
{
    if(!b)
        return -1;
    int greatInt = qFloor(a/b);
    double mod = a - greatInt*b;
    return mod;
}

double WireMesh::U(double chi,double ita)
{
    double cellDimension = mWireDia+mSaporation;
    double balX = Modulo(chi,cellDimension);
    double balY = Modulo(ita,cellDimension);
    if(balX < mWireDia  && balY < mWireDia)
        return 0;
    return 1;
}
void WireMesh::SetWireDia(double d)
{
    mWireDia = d;
}
double WireMesh::GetWireDia()
{
    return mWireDia;
}
void WireMesh::SetSaporation(double d)
{
    mSaporation = d;
}
double WireMesh::GetSaporation()
{
    return mSaporation;
}
///////////////////////SingleWire///////////////////////////////////////
SingleWire::SingleWire()
{
    mWireDia = 150e-6;
}
SingleWire::~SingleWire()
{

}
double SingleWire::U(double chi,double ita)
{
    if(qAbs(chi) < (mWireDia/2))
        return 0;
    return 1;
}
void SingleWire::SetWireDia(double d)
{
    mWireDia = d;
}
double SingleWire::GetWireDia()
{
    return mWireDia;
}
///////////////////////CrossWire///////////////////////////////////////
CrossWire::CrossWire()
{
    mWireDia = 50e-6;
}
CrossWire::~CrossWire()
{

}
double CrossWire::U(double chi,double ita)
{
    if(qAbs(chi) < (mWireDia/2) ||
            qAbs(ita) < (mWireDia/2))
        return 0;
    return 1;
}
void CrossWire::SetWireDia(double d)
{
    mWireDia = d;
}
double CrossWire::GetWireDia()
{
    return mWireDia;
}
