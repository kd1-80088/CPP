/*Q3. Write a class to find volume of a Cylinder by using following members. (volume of
Cylinder=3.14 * radius * radius *height) (write a menu driven code for it and also use modular
approach)
Class having following member functions:
Cylinder()
Cylinder(double radius, double height)
getRadius()
setRadius()
getHeight()
setHeight()
getVolume()
printVolume()
Initialize members using constructor member initializer list.*/

#include <iostream>
#define pi = 3.14
using namespace std;

class Cylinder
{
private:
    double volume;
    double radius;
    double height;

public:
    Cylinder() {}
    Cylinder(double radius, double height)
    {
        this->radius = radius;
        this->height = height;
    }
    double getRadius()
    {
        return this->radius;
    }
    void setRadius()
    {
        this->radius = radius;
    }
    double getHeight()
    {
        return this->height;
    }
    void setHeight()
    {
        this->height = height;
    }
    double getVolume()
    {
        return double(3.14) * radius * radius * height;
    }
    void printVolume()
    {
        cout << "The volume of Cylinder is = " << getVolume() << endl;
    }
};
enum Menus
{
    EXIT,
    PRINTVOLUME,

};
Menus menu_driven()
{
    int choice;
    cout << " Exit . 0" << endl;
    cout << " Printvolume . 1" << endl;
    cin >> choice;
    return Menus(choice);
}
int main()
{
    Cylinder c1;
    int choice;
    while ((choice = menu_driven()) != EXIT)
    {
        switch (choice)

        {
        case PRINTVOLUME:
            c1.printVolume();
            break;

        default:
            cout << "Invalid option" << endl;
        }
    }
    cout << "done";
    return 0;
}