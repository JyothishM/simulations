#ifndef MATHTEST_H
#define MATHTEST_H


#include <QDebug>
#include <QFile>
#include "csvwriter.h"
#include "csvreader.h"
#include "integrator.h"
#include "basicmath.h"


double y1(double x)
{
    return 0;
}
double y2(double x)
{
    return x*x/4;
}


double fn(double x,double y)
{
    return x*y;
}

SimMath::SimComplex cfn(double x,double y)
{
    return SimMath::SimComplex(0,x*y);
}

int MathTest()
{

#if 0

   CSVTable table;
   QVariantList header;
   header << "x" << "y";

   QVariantList line;
   line << 1 << 3.5;

   table << header << line << line << line;


   QFile file("testfile.csv");

   if (file.open(QIODevice::WriteOnly | QIODevice::Text))
   {

       qDebug() << "file opening succes. before fn";
       bool succes = CSVwriter::WriteCSV(&file,table);
        qDebug() << succes;
        file.close();
        qDebug() << "file closed.";
   }
   else
   {
       qDebug() << "file opening failed.";
   }

#endif

#if 0
   double val = SimMath::Integrator::SurfIntegral(&fn,&y1,&y2,0,2,0.5e-3,0.5e-3);
   qDebug() << "integral val :" << val;
   SimMath::SimComplex cVal = SimMath::Integrator::SurfIntegral(&cfn,&y1,&y2,0,2,0.5e-3,0.5e-3);
   qDebug() << "integral val :" << cVal.Real() << " +i" << cVal.Imag();
#endif

#if 0
   SimMath::SimComplex c1(3,4);
   SimMath::SimComplex c2(3.5,4.5);
   SimMath::SimComplex c3 = 5 / c1 * c2/3;

   qDebug() << "complex val :" << c3.Real() << " +i" << c3.Imag();
   SimMath::SimComplex c4 = SimMath::BasicMath::Exp(SimMath::SimComplex(0,Pi/2));
   qDebug() << "exp(i pi) =" << c4.Real() << " +i" << c4.Imag();
#endif

#if 1
   CSVTable table;
   QFile file("testcsv.csv");
   if (file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
        qDebug() << "file opening succes. before fn";
        bool succes = CSVreader::ReadCSV(&file,table,",","\"");
        qDebug() << succes;
        file.close();
        qDebug() << "file closed.";

        //displaying table
        int i=1;
        foreach(QVariantList line,table)
        {
            qDebug() << "line" << i++;
            foreach(QVariant cell,line)
            {
                qDebug() << cell.toString();
            }
        }
   }
   else
   {
       qDebug() << "file opening failed.";
   }
#endif
}


#endif // MATHTEST_H
