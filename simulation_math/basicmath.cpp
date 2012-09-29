#include "basicmath.h"
#include <qmath.h>

namespace SimMath
{
namespace BasicMath
{

SimComplex Exp(SimComplex c)
{
    double expval = qExp(c.Real());
    SimComplex value(expval* qCos(c.Imag()),
                     expval* qSin(c.Imag()));
    return value;
}
SimComplex Expi(double phase)
{
    return Exp(i(phase));
}
SimComplex i(double phase)
{
    return SimComplex(0,phase);
}

} // namespace BasicMath
} // namespace SimMath
