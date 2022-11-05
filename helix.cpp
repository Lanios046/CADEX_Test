#include "helix.h"
#include <iostream>
using namespace std;

Helix::Helix(double x,double y,double z,double radius,double step):Circle(x,y,radius)
{
    this->step=step;
    center.z=z;
}

Point3D Helix::point(double t)
{
    int NumOfRounds=0;
    double OneRound = sqrt((2*M_PI*radius)*(2*M_PI*radius)+(step*step));
    if(t>=OneRound)while(t>=OneRound)
    {
        t-=OneRound;
        NumOfRounds++;
    }
    double angle=t/radius;
    return Point3D(center.x+(radius*cos(angle)),
                   center.y+(radius*cos(angle)),
                   center.z+(NumOfRounds*step)+(t*(step/OneRound)));
}

double Helix::FDerivate(double t)
{
    int NumOfRounds=0;
    double OneRound = sqrt((2*M_PI*radius)*(2*M_PI*radius)+(step*step));
    if(t>=OneRound)while(t>=OneRound)
    {
        t-=OneRound;
        NumOfRounds++;
    }
    double angle=t/radius;
    Point3D currentPoint(center.x+(radius*cos(angle)),
                         center.y+(radius*cos(angle)),
                         center.z+(NumOfRounds*step)+(t*(step/OneRound)));//point coordinates
    return (currentPoint.x-center.x)/(center.y/currentPoint.y);//First derivate
}




