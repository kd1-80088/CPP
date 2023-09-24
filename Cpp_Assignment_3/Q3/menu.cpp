#include "./menu.h"
#include <iostream>
using namespace std;

Menus menu_driven()
{
    int choice;
    cout << " Exit . 0" << endl;
     cout << " calculatevolume . 1" << endl;
    cout << " Printvolume . 2" << endl;
    cin>>choice;


    return Menus(choice);
}