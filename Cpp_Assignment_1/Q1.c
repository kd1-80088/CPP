#include <stdio.h>
/*  Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members
day, month, year. Implement the following functions.
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate); */

struct Date
{
    int day;
    int month;
    int year;
};
void initDate(struct Date *ptrDate);
void printDateOnConsole(struct Date *ptrDate);
void acceptDateFromConsole(struct Date *ptrDate);

void initDate(struct Date *ptrDate)
{
    ptrDate->day = 01;
    ptrDate->month = 01;
    ptrDate->year = 1900;
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter the day = ");
    scanf("%d", &ptrDate->day);
    printf("Enter the month = ");
    scanf("%d", &ptrDate->month);
    printf("Enter the year = ");
    scanf("%d", &ptrDate->year);
}

void printDateOnConsole(struct Date *ptrDate)
{
    printf("the date is= %d/%d/%d", ptrDate->day, ptrDate->month, ptrDate->year);
}

int main()
{
    struct Date d1;
    int choice;
    do
    {
        printf("\nEnter choice 1 \n 2. \n 3. \n 0.exit \n"); // ctrl shift i
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            initDate(&d1);
            printDateOnConsole(&d1);
            break;

        case 2:
            acceptDateFromConsole(&d1);
            break;
        case 3:
            // acceptDateFromConsole(&d1);
            printDateOnConsole(&d1);

        default:
            break;
        }
    } while (choice != 0);
}