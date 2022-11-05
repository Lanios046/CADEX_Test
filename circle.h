#ifndef CIRCLE_H
#define CIRCLE_H
#include "point3d.h"
#include <cmath>


class Circle
{
protected:
    Point3D center;
    double radius;
public:
    Circle();
    Circle(double x,double y,double radius);
    virtual Point3D point(double t);
    virtual double FDerivate(double t);
    virtual double getRadius();
};

#endif // CIRCLE_H
