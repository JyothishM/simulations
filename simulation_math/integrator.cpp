#include "integrator.h"
#include "math.h"
#include <QDebug>

namespace SimMath
{

Integrator::Integrator()
{
}
double Integrator::SurfIntegral(DDFnPtr fn,double x1,double x2,double y1,double y2,double xtol,double ytol)
{
    double I = 0;
    double dA = xtol*ytol;

    int xSign = 1;
    int xCount = FindEvalCount(x1,x2,xtol,xSign);
    double x = x1;
    for(int i=0; i<xCount; i++)
    {
        int ySign = 1;
        int yCount = FindEvalCount(y1,y2,ytol,ySign);
        double y = y1;
        int netSign = xSign*ySign;
        for(int j=0; j<yCount; j++ )
        {
           I += netSign * fn(x,y) * dA;
           y += ySign * ytol;
        }
        x += xSign*xtol;
    }
    return I;
}
double Integrator::SurfIntegral(DDFnPtr fn,double x1,double x2,DFnPtr Y1,DFnPtr Y2,double xtol,double ytol)
{
    double I = 0;
    double dA = xtol*ytol;

    int xSign = 1;
    int xCount = FindEvalCount(x1,x2,xtol,xSign);
    double x = x1;
    for(int i=0; i<xCount; i++)
    {
        int ySign = 1;
        double y = Y1(x);

        int yCount = FindEvalCount(y,Y2(x),ytol,ySign);
        int netSign = xSign*ySign;
        for(int j=0; j<yCount; j++ )
        {
           I += netSign * fn(x,y) * dA;
           y += ySign * ytol;
        }
        x += xSign*xtol;
    }
    return I;
}
double Integrator::SurfIntegral(DDFnPtr fn,DFnPtr X1,DFnPtr X2,double y1,double y2,double xtol,double ytol)
{
    double I = 0;
    double dA = xtol*ytol;

    int ySign = 1;
    double y = y1;
    int yCount = FindEvalCount(y1,y2,ytol,ySign);
    for(int j=0; j<yCount; j++)
    {
        int xSign = 1;
        double x = X1(y);
        int xCount = FindEvalCount(x,X2(y),xtol,xSign);
        int netSign = xSign*ySign;
        for(int i=0; i<xCount; i++ )
        {
           I += fn(x,y) * netSign  * dA;
           x += xSign * xtol;
        }
        y += ySign*ytol;
    }
    return I;
}
// complex
SimComplex Integrator::SurfIntegral(CFnPtr fn,double x1,double x2,double y1,double y2,double xtol,double ytol)
{
    SimComplex I = 0;
    double dA = xtol*ytol;

    int xSign = 1;
    int xCount = FindEvalCount(x1,x2,xtol,xSign);
    double x = x1;
    for(int i=0; i<xCount; i++)
    {
        int ySign = 1;
        int yCount = FindEvalCount(y1,y2,ytol,ySign);
        double y = y1;
        int netSign = xSign*ySign;
        for(int j=0; j<yCount; j++ )
        {
           I += netSign * fn(x,y) * dA;
           y += ySign * ytol;
        }
        x += xSign*xtol;
    }
    return I;
}
SimComplex Integrator::SurfIntegral(CFnPtr fn,double x1,double x2,DFnPtr Y1,DFnPtr Y2,double xtol,double ytol)
{
    SimComplex I;
    double dA = xtol*ytol;

    int xSign = 1;
    int xCount = FindEvalCount(x1,x2,xtol,xSign);
    double x = x1;
    for(int i=0; i<xCount; i++)
    {
        int ySign = 1;
        double y = Y1(x);

        int yCount = FindEvalCount(y,Y2(x),ytol,ySign);
        int netSign = xSign*ySign;
        for(int j=0; j<yCount; j++ )
        {
           I += netSign * fn(x,y) * dA;
           y += ySign * ytol;
        }
        x += xSign*xtol;
    }
    return I;
}
SimComplex Integrator::SurfIntegral(CFnPtr fn,DFnPtr X1,DFnPtr X2,double y1,double y2,double xtol,double ytol)
{
    SimComplex I;
    double dA = xtol*ytol;

    int ySign = 1;
    double y = y1;
    int yCount = FindEvalCount(y1,y2,ytol,ySign);
    for(int j=0; j<yCount; j++)
    {
        int xSign = 1;
        double x = X1(y);
        int xCount = FindEvalCount(x,X2(y),xtol,xSign);
        int netSign = xSign*ySign;
        for(int i=0; i<xCount; i++ )
        {
           I += netSign * fn(x,y) * dA;
           x += xSign * xtol;
        }
        y += ySign*ytol;
    }
    return I;
}

// private
 int Integrator::FindEvalCount(double start,double stop,double tol,int &sign)
 {
     sign = (stop>start)?1:-1;
     int count = abs((stop-start)/tol);
     return count;
 }

} // namespace SimMath
