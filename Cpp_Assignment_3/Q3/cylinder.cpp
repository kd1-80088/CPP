#include "./cylinder.h"

Cylinder::Cylinder(double radius, double height)
    {
        this->radius = radius;
        this->height = height;
    }

    double Cylinder::getRadius()
    {
        return this->radius;
    }
    void Cylinder::setRadius()
    {
        this->radius = radius;
    }
    double Cylinder::getHeight()
    {
        return this->height;
    }
    void Cylinder::setHeight()
    {
        this->height = height;
    }
    double Cylinder::getVolume()
    {
        return double(3.14) * radius * radius * height;
    }
    void Cylinder::printVolume()
    {
        cout << "The volume of Cylinder is = " << getVolume() << endl;
    }
