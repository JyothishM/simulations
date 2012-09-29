#ifndef APPERTURE_H
#define APPERTURE_H

class Apperture
{
public:
    Apperture();
    virtual ~Apperture();
    virtual double U(double chi,double ita)=0;
    void SetOrginPos(double x,double y);
    double GetOrginPosX();
    double GetOrginPosY();
    void SetAngle(double angle);
    double GetAngle();
private:
    double mOrginPosX;
    double mOrginPosY;
    double mAngle;
};

// appertures
class SingleSlit : public Apperture
{
public:
    SingleSlit();
    virtual ~SingleSlit();
    virtual double U(double chi,double ita);
    void SetSlitW(double w);
    double GetSlitW();
    void SetSlitH(double h);
    double GetSlitH();
private:
    double mSlitW;
    double mSlitH;
};

class DoubleSlit : public Apperture
{
public:
    DoubleSlit();
    virtual ~DoubleSlit();
    virtual double U(double chi,double ita);
    void SetSlitW(double w);
    double GetSlitW();
    void SetSlitH(double h);
    double GetSlitH();
    void SetSaporation(double d);
    double GetSaporation();
private:
    double mSlitW;
    double mSlitH;
    double mSaporation;
};

class CircularApperture : public Apperture
{
public:
    CircularApperture();
    virtual ~CircularApperture();
    virtual double U(double chi,double ita);
    void SetRadius(double r);
    double GetRadius();
private:
    double mRad;
};

class WireMesh : public Apperture
{
public:
    WireMesh();
    virtual ~WireMesh();
    virtual double U(double chi,double ita);
    void SetWireDia(double d);
    double GetWireDia();
    void SetSaporation(double d);
    double GetSaporation();
private:
    double mWireDia;
    double mSaporation;
};

class SingleWire : public Apperture
{
public:
    SingleWire();
    virtual ~SingleWire();
    virtual double U(double chi,double ita);
    void SetWireDia(double d);
    double GetWireDia();
private:
    double mWireDia;
};

class CrossWire : public Apperture
{
public:
    CrossWire();
    virtual ~CrossWire();
    virtual double U(double chi,double ita);
    void SetWireDia(double d);
    double GetWireDia();
private:
    double mWireDia;
};

#endif // APPERTURE_H
