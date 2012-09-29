#ifndef SIMCOMPLEX_H
#define SIMCOMPLEX_H

#include "simulation_math_global.h"
#include <QString>

namespace SimMath
{

class SIMULATION_MATHSHARED_EXPORT SimComplex
{
public:
    SimComplex();
    SimComplex(double real,double img=0);
    void SetReal(double real);
    void SetImag(double img);
    double Real();
    double Imag();
    double Mod();
    QString ToString();
    static SimComplex Conju(SimComplex& c2);
    // operators
    SimComplex operator+ (SimComplex c2);
    SimComplex operator- (SimComplex c2);
    SimComplex operator* (SimComplex c2);
    SimComplex operator/ (SimComplex c2);
    SimComplex operator+ (double d);
    SimComplex operator- (double d);
    SimComplex operator* (double d);
    SimComplex operator/ (double d);
    SimComplex& operator+= (SimComplex c2);
    SimComplex& operator-= (SimComplex c2);
    SimComplex& operator*= (SimComplex c2);
    SimComplex& operator/= (SimComplex c2);
    SimComplex& operator+= (double d);
    SimComplex& operator-= (double d);
    SimComplex& operator*= (double d);
    SimComplex& operator/= (double d);
private:
    double mReal;
    double mImg;
};

} // namespace SimMath

SimMath::SimComplex SIMULATION_MATHSHARED_EXPORT operator+ (double,SimMath::SimComplex c2);
SimMath::SimComplex SIMULATION_MATHSHARED_EXPORT operator- (double,SimMath::SimComplex c2);
SimMath::SimComplex SIMULATION_MATHSHARED_EXPORT operator* (double,SimMath::SimComplex c2);
SimMath::SimComplex SIMULATION_MATHSHARED_EXPORT operator/ (double,SimMath::SimComplex c2);


#endif // SIMCOMPLEX_H
