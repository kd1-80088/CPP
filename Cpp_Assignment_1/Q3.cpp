// Q3. Write a menu driven program for Student in CPP language. Create a class student with data
// members roll no, name and marks. Implement the following functions
// void initStudent();
// void printStudentOnConsole();
// void acceptStudentFromConsole();

#include <iostream>
using namespace std;

class student
{
private:
    int rollno;
    string name;
    float marks;

public:
    void initStudent()
    {
        rollno = 1;
        name = 'king';
        marks = 70;
    }
    void acceptStudentFromConsole()
    {
        cout << "student roll no\n";
        cin >> rollno;
        cout << "student name \n";
        cin >> name;
        cout << "student marks\n";
        cin >> marks;
    }

    void printStudentOnConsole()
    {
        cout << " The details are \n";
        cout << "roll no = " << rollno << endl;
        cout << "Name = " << name << endl;
        cout << "marks is = " << marks << endl;
    }
};

int main()
{
    int choice;
    student s1;
    do
    {
        printf("\nEnter choice 1 \n 2. \n 3. \n 0.exit \n"); // ctrl shift i
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            s1.initStudent();
            s1.printStudentOnConsole();
            break;

        case 2:
            s1.acceptStudentFromConsole();

            break;
        case 3:
            // acceptDateFromConsole(&d1);
            s1.printStudentOnConsole();

        default:
            break;
        }
    } while (choice != 0);
}