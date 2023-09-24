/*Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
collected. Model this tollbooth with a class called tollbooth.
The two data items are a type unsigned int to hold the total number of cars, and a type double to
hold the total amount of money collected.
A constructor initializes all data members to 0. A member function called payingCar() increments
the car total and adds 0.50 to the cash total. An other function, called nopayCar()
increments the car total but adds nothing to the cash total. Finally, a member function called
printOnConsole() displays the two totals and number of paying as well as non paying cars total.
( write a menu driven code for it)*/

#include <iostream>
using namespace std;

class Tollbooth
{
private:
    int totalcars;
    double totalamount;

public:
    Tollbooth()
    {
        this->totalcars = 0;
        this->totalamount = 0;
    }
    int totalcars_Not_Paying()
    {
        return this->totalamount;
    }
    float totalcars_Paying()
    {
        return this->totalamount += 0.5;
    }
    void payingCar()
    {
        ++totalcars;
         totalcars_Paying();
    }

    void noPayCar()
    {
        ++totalcars;
      totalcars_Not_Paying();
    }
    void print_On_Console()
    {
        cout << " CONSOLE " << endl;
        cout << " total paying cars = " << (2*this->totalamount) << endl;
        cout << " total Amount= " << this->totalamount << endl;
        cout<<" total non paying cars = "<<this->totalcars-(2*this->totalamount);
    }
};
enum Emenu
{
    EXIT,
    PAYING_CAR_PASSED,
    NON_PAYING_CAR_PASSED,
    PRINT_TOTAL
};

Emenu menu()
{
    int choice;
    cout << "********************" << endl;
    cout << "0.EXIT" << endl;
    cout << "1.PAYING_CAR_PASSED" << endl;
    cout << "2.NON_PAYING_CAR_PASSED" << endl;
    cout << "3.TOTAL_AMOUNT_COLLECTRD" << endl;
    cout << "ENTER_CHOICE" << endl;
    cin >> choice;
    cout << "********************" << endl;
    return Emenu(choice);
}

int main()
{
    Emenu choice;
    Tollbooth t1;

    while (choice= menu())
    {
        switch (choice)
        {
        case PAYING_CAR_PASSED:
            cout << "one_paying_car passed" << endl;
            t1.payingCar();
            break;

        case NON_PAYING_CAR_PASSED:
            cout << "one_nonpaying_car passed" << endl;
            t1.noPayCar();
            break;
        
        case PRINT_TOTAL:
            t1.print_On_Console();
            break;

        default:
            cout << "enter valid choice" << endl;
            break;
        }
    }
    
}

