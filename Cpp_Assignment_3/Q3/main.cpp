#include "./cylinder.h"
#include "./menu.h"

int main()
{
    Cylinder c1;
    Menus choice;
    while ((choice = menu_driven()) != EXIT)
    {
        switch (choice)

        {
        case GETVOLUME:
            c1.getVolume();
            break;
        case PRINTVOLUME:
            c1.printVolume();
            break;

        default:
            cout << "Invalid option";
        }
    }
    cout << "done";
    return 0;
}