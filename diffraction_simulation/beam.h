#ifndef BEAM_H
#define BEAM_H

class Beam
{
public:
    Beam();
    virtual double I(double x,double y)=0;
};

class RectBeam : public Beam
{
public:
    RectBeam();
    virtual ~RectBeam();
    virtual double I(double x,double y);
    void SetRadius(double r);
    double GetRadius();
private:
    double mRad;
};

#endif // BEAM_H
