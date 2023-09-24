#ifndef CYLINDER_H
#define CYLINDER_H
#include<iostream>

using namespace std;
class Cylinder
{
private:
    double volume;
    double radius;
    double height;

public:
    Cylinder(double radius = 10, double height = 5);
    double getRadius();
    void setRadius();
    double getHeight();
    void setHeight();
    double getVolume();
    void printVolume();
};
#endif