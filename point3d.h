#ifndef POINT3D_H
#define POINT3D_H


class Point3D
{
public:
    double x;
    double y;
    double z;
    Point3D(double x=0,double y=0,double z=0);
    void Set(double x=0,double y=0,double z=0);
};

#endif // POINT3D_H
