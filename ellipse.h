#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "point3d.h"
#include "circle.h"
#include <cmath>


class Ellipse:public Circle
{
private:
    double radius2;//radius Y
public:
    Ellipse(double x,double y,double radius,double radius2);
    Point3D point(double t)override;
    double FDerivate(double t)override;
};

#endif // ELLIPSE_H
