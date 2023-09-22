// Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
// Date is having data members day, month, year. Implement the following functions.
// void initDate();
// void printDateOnConsole();
// void acceptDateFromConsole();
// bool isLeapYear();
#include <iostream>

struct Date
{
    int day;
    int month;
    int year;

    void initDate()
    {
        day = 01;
        month = 01;
        year = 1900;
    }

    void acceptDateFromConsole()
    {
        printf("Enter the day = ");
        scanf("%d", &day);
        printf("Enter the month = ");
        scanf("%d", &month);
        printf("Enter the year = ");
        scanf("%d", &year);
    }

    void printDateOnConsole()
    {
        printf("the date is= %d/%d/%d", day,month,year);
    }
    bool isLeapYear()
    {
        if((year%100 !=0)&&(year%4==0))
        {
            printf("\n the leap year \n");
            return true;
        }
        else 
        printf("Not a leap year \n");
        return false;
    }
};
void initDate(struct Date *ptrDate);
void printDateOnConsole(struct Date *ptrDate);
void acceptDateFromConsole(struct Date *ptrDate);

int main()
{
    struct Date d1,a;
    int choice;
    // d1.initDate();
    // d1.printDateOnConsole();
    do
    {
        printf("\nEnter choice 1 \n 2. \n 3. \n 0.exit \n"); // ctrl shift i
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            d1.initDate();
            d1.isLeapYear();
            d1.printDateOnConsole();
            break;

        case 2:
            d1.acceptDateFromConsole();
            d1.isLeapYear();
            d1.printDateOnConsole();
            break;
        case 3:
            // acceptDateFromConsole(&d1);
            d1.printDateOnConsole();

        default:
            break;
        }
    } while (choice != 0);
}