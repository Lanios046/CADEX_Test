#ifndef HELIX_H
#define HELIX_H
#include "point3d.h"
#include "circle.h"
#include <cmath>


class Helix:public Circle
{
private:
    double step;
public:
    Helix(double x,double y,double z,double radius,double step);
    Point3D point(double t)override;
    double FDerivate(double t)override;
};

#endif // HELIX_H


