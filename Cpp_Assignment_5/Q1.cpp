/*Q1. Write a menu driven program for Student management.
In main(), create Array of Objects and provide facility for accept, print, search and sort.
For student accept name, gender, rollNumber and marks of three subjects from user and print name,
rollNumber, gender and percentage.
Provide global functions void sortRecords(Studuent[] arr) and int searchRecords(Student[] arr) for
sorting and searching array.
Search function returns index of found Student, otherwise returns -1.*/

#include <iostream>

using namespace std;
#define size 3
class Student
{
private:
    string name;
    string gender;
    int rollNumber;
    float *marks;

public:
    Student()
    {
        this->name = name;
        this->gender = gender;
        this->rollNumber = rollNumber;
        this->marks = new float[3];
    }
    void accept()
    {

        cout << " Enter students name -: ";
        cin >> name;
        cout << "gender -: ";
        cin >> gender;
        cout << " roll number -: ";
        cin >> rollNumber;

        for (int i = 0; i < 3; i++)
        {
            float temp;
            cout << " enter marks -: ";
            cin >> temp;
            marks[i] = temp;
        }
    }
    void print()
    {
        cout << "Student Name = " << name << endl;
        cout << " gender      = " << gender << endl;
        cout << "Roll number  = " << rollNumber << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Marks        = " << marks[i] << endl;
        }
    }
    double percentage()
    {
        int p = 0, ans = 0;
        for (int i = 0; i < size; i++)
        {
            p += marks[i];
        }
        ans = p / 3;
        cout<<"percentage = "<<ans<<endl;
        return ans;
    }

    int getRollNumber()
    {
        return this->rollNumber;
    }
};
void sortRecords(Student arr[])
{
    int temp;
    bool flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j].percentage() > arr[j + 1].percentage())
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
}


int searchRecords(Student arr[])
{
    int key;
    cout << "Enter the key Element " << endl;
    cin >> key;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].getRollNumber() == key)
        {
            cout << "index = " << i << endl;
            return 1;
        }
    }
    return -1;
}
enum Emenu
{
    EXIT,
    ACCEPT_DATA,
    RECORDS_SEARCHING,
    RECORDS_SORTING,
    PRINT_DATA
};

Emenu menu()
{
    int choice;
    cout << "******************************************"<< endl;
    cout << "select any choice " << endl;
    cout << "0.exit " << endl;
    cout << "1. for accepting records " << endl;
    cout << "2.for searching records "  << endl;
    cout << "3.for sorting records " << endl;
    cout << "4.printing records " << endl;
    cin >> choice;
    cout<<"***********************************************"<<endl;
    return Emenu(choice);
}
int main()
{
    // Student arr[size];
    // int result;
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i].accept();
    // }
    // // for (int i = 0; i < size; i++)
    // // {
    // //     arr[i].print();
    // // }
    // // for (int i = 0; i < size; i++)
    // // {
    // //     arr[i].percentage();
    // // }
    // sortRecords(arr);
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i].print();
    // }
    
    // result = searchRecords(arr);
    // if (result == -1)
    //     cout << " Element is Not found " << endl;
    // else
    //     cout << " Key Element Found " << endl;

    Emenu choice;
    Student s[size];
    while((choice=menu())!=0)
    {
        switch (choice)
        {
        case ACCEPT_DATA: 
            for (int i = 0; i < size; i++)
            {
             s[i].accept();
            }
            break;

        case RECORDS_SEARCHING: 
            searchRecords(s);
            break;

        case RECORDS_SORTING:
            sortRecords(s); 
            break;

        case PRINT_DATA:
            for (int i = 0; i < size; i++)
            {
                s[i].print();
            } 
            break;

        default:
            cout<<"enter valid choice"<<endl;
            break;
        }
    }
    return 0;
}