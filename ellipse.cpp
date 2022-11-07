#include "ellipse.h"

Ellipse::Ellipse(double x,double y,double radius,double radius2):Circle(x,y,radius)
{
    if(radius>=0)this->radius2=radius2;
}
Point3D Ellipse::point(double t)
{
    if(t>M_PI*(radius+radius2))while (t>M_PI*(radius+radius2))//check number of turn
    {
        t-=M_PI*(radius+radius2);
    }
    double angleAlpha;
    double TgAngleBeta=0;
    if(radius>radius2)
    {
        angleAlpha=t/radius;
        TgAngleBeta=(radius2*sin(angleAlpha)/(radius*cos(angleAlpha)));//tg of dependent angle
        return Point3D(center.x+(radius*cos(atan(TgAngleBeta))),center.y+(radius2*sin(atan(TgAngleBeta))),0);//point coordinates
    }
    else
    {
        angleAlpha=t/radius2;
        TgAngleBeta=(radius*sin(angleAlpha)/(radius2*cos(angleAlpha)));//tg of dependent angle
        return Point3D(center.x+(radius2*cos(atan(TgAngleBeta))),center.y+(radius*sin(atan(TgAngleBeta))),0);//point coordinates
    }

}
double Ellipse::FDerivate(double t)
{
    if(t>M_PI*(radius+radius2))while (t>M_PI*(radius+radius2))//check number of turn
    {
        t-=M_PI*(radius+radius2);
    }
    Point3D PointOnEllipce(0,0,0);
    Point3D Foc1(0,0,0);
    Point3D Foc2(0,0,0);
    if(radius>radius2)
    {
        double c=sqrt(radius*radius-radius2*radius2);//horizontal orientation
        double angleAlpha=t/(M_PI*radius);
        double TgAngleBeta=(radius2*sin(angleAlpha)/(radius*cos(angleAlpha)));//tg of dependent angle
        PointOnEllipce.Set(center.x+(radius*cos(atan(TgAngleBeta))),center.y+(radius2*sin(atan(TgAngleBeta))),0);//point coordinates
        Foc1.Set(center.x+c,0,0);
        Foc2.Set(center.x-c,0,0);
    }
    else
    {
        double c=sqrt(radius2*radius2-radius*radius);//vertical orientation
        double angleAlpha=t/(M_PI*radius);
        double TgAngleBeta=(radius*sin(angleAlpha)/(radius2*cos(angleAlpha)));//tg of dependent angle
        PointOnEllipce.Set(center.x+(radius2*cos(atan(TgAngleBeta))),center.y+(radius*sin(atan(TgAngleBeta))),0);//point coordinates
        Foc1.Set(0,center.y+c,0);
        Foc2.Set(0,center.y-c,0);
    }
    double k1=(PointOnEllipce.x-Foc1.x)/(PointOnEllipce.y-Foc1.y);//tan of 1st line
    double k2=(PointOnEllipce.x-Foc2.x)/(PointOnEllipce.y-Foc2.y);//tan of 2nd line
    double TgAnglePhy=(k2-k1)/(1-k1*k2);//tg of crossing
    return tan((1-atan(TgAnglePhy))/2);//Derivate
}
