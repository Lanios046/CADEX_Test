#include "circle.h"

Circle::Circle(){}
Circle::Circle(double x,double y,double radius)
{
    center.x=x;
    center.y=y;
    center.z=0;
    if(radius>=0)this->radius=radius;
}

Point3D Circle::point(double t)
{
    if(t>radius*2*M_PI) while (t>radius*2*M_PI)//check number of turn
    {
        t-=radius*2*M_PI;
    }
    double angle=t/radius;
    return Point3D(center.x+(radius*cos(angle)),center.y+(radius*sin(angle)),0);//point coordinates
}

double Circle::FDerivate(double t)
{
    if(t>radius*2*M_PI) while (t>radius*2*M_PI)//check number of turn
    {
        t-=radius*2*M_PI;
    }
    double angle=t/radius;
    Point3D currentPoint(center.x+(radius*cos(angle)),center.y+(radius*sin(angle)),0);//point coordinates
    return (currentPoint.x-center.x)/(center.y/currentPoint.y);//First derivate
}
double Circle::getRadius()
{
    return radius;
}
