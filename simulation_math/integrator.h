#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "simulation_math_global.h"
#include "BasicMath/simcomplex.h"

namespace SimMath
{

typedef double(*DFnPtr)(double);
typedef double(*DDFnPtr)(double,double);
typedef SimComplex(*CFnPtr)(double,double);

class SIMULATION_MATHSHARED_EXPORT Integrator
{
public:
    Integrator();

    static double SurfIntegral(DDFnPtr fn,double x1,double x2,double y1,double y2,double xtol=1e-3,double ytol=1e-3);
    static double SurfIntegral(DDFnPtr fn,double x1,double x2,DFnPtr Y1,DFnPtr Y2,double xtol=1e-3,double ytol=1e-3);
    static double SurfIntegral(DDFnPtr fn,DFnPtr X1,DFnPtr X2,double y1,double y2,double xtol=1e-3,double ytol=1e-3);

    static SimComplex SurfIntegral(CFnPtr fn,double x1,double x2,double y1,double y2,double xtol=1e-3,double ytol=1e-3);
    static SimComplex SurfIntegral(CFnPtr fn,double x1,double x2,DFnPtr Y1,DFnPtr Y2,double xtol=1e-3,double ytol=1e-3);
    static SimComplex SurfIntegral(CFnPtr fn,DFnPtr X1,DFnPtr X2,double y1,double y2,double xtol=1e-3,double ytol=1e-3);
private:
    inline static int FindEvalCount(double start,double stop,double tol,int &sign);
};

} // namespace SimMath

#endif // INTEGRATOR_H
