#ifndef FHDIFFRACTION_H
#define FHDIFFRACTION_H

#include <QObject>
#include "BasicMath/simcomplex.h"

class Beam;
class Apperture;

class FHDiffraction : public QObject
{
    Q_OBJECT

    friend SimMath::SimComplex IntegrantFroCur(double chi,double ita);
public:
    FHDiffraction(QObject* parent=0);
    virtual ~FHDiffraction();
    void SetZ(double z);
    double GetZ();
    void SetLamda(double lamda);
    double GetLamda();
    void SetBeam(Beam* beam);
    Beam* GetBeam();
    void SetApperture(Apperture* apperture);
    Apperture* GetApperture();
    virtual bool Init();    // should be called after setting all the values.
    virtual double IntensityAt(double x,double y);
    void SetEvaluationConfig(double xMin,double xMax,double yMin,double yMax,double tol);
private:
    SimMath::SimComplex Integrant(double chi,double ita);
    static SimMath::SimComplex IntegrantFroCur(double chi,double ita);
    static FHDiffraction* mCurObj;

    double mZ;
    double mLamda;
    double mCurX,mCurY;
    Beam* mBeam;
    Apperture* mApperture;

    // evaluation config
    double mXmin,mXmax;
    double mYmin,mYmax;
    double mTol;

    // calculated values.
    double mK;
    SimMath::SimComplex mConst1,mConst2,mConst3;
};

#endif // FHDIFFRACTION_H
