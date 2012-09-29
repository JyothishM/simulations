#ifndef BASICMATH_H
#define BASICMATH_H

#include "simulation_math_global.h"
#include "BasicMath/MathConsts.h"
#include "BasicMath/simcomplex.h"

namespace SimMath
{
namespace BasicMath
{

SimComplex SIMULATION_MATHSHARED_EXPORT Exp(SimComplex c);
SimComplex SIMULATION_MATHSHARED_EXPORT Expi(double phase);
SimComplex SIMULATION_MATHSHARED_EXPORT i(double phase);

}
} // namespace SimMath

#endif // BASICMATH_H
