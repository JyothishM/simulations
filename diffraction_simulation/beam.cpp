#include "beam.h"

Beam::Beam()
{
}
///////////////////////RectBeam//////////////////////////////////////////
RectBeam::RectBeam()
{
    mRad = 0.5e-3;
}
RectBeam::~RectBeam()
{

}
double RectBeam::I(double x,double y)
{
    if((x*x+y*y)<=(mRad*mRad))
        return 1;
    return 0;
}
void RectBeam::SetRadius(double r)
{
    mRad = r;
}
double RectBeam::GetRadius()
{
    return mRad;
}
