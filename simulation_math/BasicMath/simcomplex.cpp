#include "simcomplex.h"
#include <qmath.h>

namespace SimMath
{

SimComplex::SimComplex()
{
    mReal = 0;
    mImg = 0;
}
SimComplex::SimComplex(double real,double img)
{
    mReal = real;
    mImg = img;
}
void SimComplex::SetReal(double real)
{
    mReal = real;
}
void SimComplex::SetImag(double img)
{
    mImg = img;
}
double SimComplex::Real()
{
    return mReal;
}
double SimComplex::Imag()
{
    return mImg;
}
double SimComplex::Mod()
{
    return qSqrt(mReal*mReal + mImg*mImg);
}
QString SimComplex::ToString()
{
    return QString(" %0 +i %1 ").arg(mReal).arg(mImg);
}
SimComplex SimComplex::Conju(SimComplex& c2)
{
    SimComplex C(c2.Real(),
                 -1*c2.Imag());
    return C;
}

// operators
SimComplex SimComplex::operator+ (SimComplex c2)
{
    SimComplex C(mReal+c2.Real(),
                 mImg+c2.Imag());
    return C;
}
SimComplex SimComplex::operator- (SimComplex c2)
{
    SimComplex C(mReal-c2.Real(),
                 mImg-c2.Imag());
    return C;
}
SimComplex SimComplex::operator* (SimComplex c2)
{
    SimComplex C(mReal*c2.Real() - mImg*c2.Imag(),
                 mReal*c2.Imag() + mImg*c2.Real());
    return C;
}
SimComplex SimComplex::operator/ (SimComplex c2)
{
    SimComplex C = (Conju(c2) * (*this))/(c2.Real()*c2.Real() + c2.Imag()*c2.Imag());
    return C;
}
SimComplex SimComplex::operator+ (double d)
{
    SimComplex C(mReal+d,
                 mImg);
    return C;
}
SimComplex SimComplex::operator- (double d)
{
    SimComplex C(mReal-d,
                 mImg);
    return C;
}
SimComplex SimComplex::operator* (double d)
{
    SimComplex C(mReal*d,
                 mImg*d);
    return C;
}
SimComplex SimComplex::operator/ (double d)
{
    SimComplex C(mReal/d,
                 mImg/d);
    return C;
}
SimComplex& SimComplex::operator+= (SimComplex c2)
{
    *this = operator +(c2);
    return *this;
}
SimComplex& SimComplex::operator-= (SimComplex c2)
{
    *this = operator -(c2);
    return *this;
}
SimComplex& SimComplex::operator*= (SimComplex c2)
{
    *this = operator *(c2);
    return *this;
}
SimComplex& SimComplex::operator/= (SimComplex c2)
{
    *this = operator /(c2);
    return *this;
}
SimComplex& SimComplex::operator+= (double d)
{
    *this = operator +(d);
    return *this;
}
SimComplex& SimComplex::operator-= (double d)
{
    *this = operator -(d);
    return *this;
}
SimComplex& SimComplex::operator*= (double d)
{
    *this = operator *(d);
    return *this;
}
SimComplex& SimComplex::operator/= (double d)
{
    *this = operator /(d);
    return *this;
}

} // namespace SimMath

///////////////////////External operators////////////////////////////

SimMath::SimComplex operator+ (double d,SimMath::SimComplex c2)
{
    return c2+d;
}
SimMath::SimComplex operator- (double d,SimMath::SimComplex c2)
{
    return c2-d;
}
SimMath::SimComplex operator* (double d,SimMath::SimComplex c2)
{
    return c2*d;
}
SimMath::SimComplex operator/ (double d,SimMath::SimComplex c2)
{
    return c2/d;
}
