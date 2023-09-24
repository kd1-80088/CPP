/*Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide necessary constructors.*/

#include <iostream>
using namespace std;

class Box
{
private:
    int length;
    int width;
    int height;

public:
    Box()
    {
        this->length;
        this->width;
        this->height;
    }
    void accept_Values()
    {
        cout << "length is = ";
        cin >> length;
        cout << "width is = ";
        cin >> width;
        cout << "heigth is = ";
        cin >> height;
    }
    int calculate_Volume()
    {
        return this->length * this->width * this->height;
    }
    void display_Volume()
    {
        cout << "Volume = " << calculate_Volume() << endl;
    }
};

enum KMenu
{
    EXIT,
    ACCEPT_VALUES,
    CALCULATE_VOLUME,
    DISPLAY_VOLUME
};
KMenu menu_driven()
{
    int choice;
    cout << "-------------------" << endl;
    cout << " Exit. 0" << endl;
    cout << "Accept values. 1" << endl;
    cout << "calculate volume. 2 " << endl;
    cout << "display volume . 3 " << endl;
    cout << "Enter your choice :- ";
    cin >> choice;
    cout << "-----------------------------";
    return KMenu(choice);
}
int main()
{
    int c;
    Box b1;

    while ((c = menu_driven()) != EXIT)
    {
        switch (c)
        {
        case  ACCEPT_VALUES:
            cout << "Enter values of sides " << endl;
            b1.accept_Values();
            break;
        case CALCULATE_VOLUME:
            b1.calculate_Volume();
            break;
        case DISPLAY_VOLUME:
            b1.display_Volume();
            break;
        default:
            cout << " Invalid case ";
        }
    }

    return 0;
}
