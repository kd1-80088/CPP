/*Q1. Implement following classes. Test all functionalities in main().Insted of char[] use string
datatype*/
// Example of Association(composition)

#include <iostream>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void setDay(int day)
    {
        this->day = day;
    }
    int getDay()
    {
        return this->day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    int getMonth()
    {
        return this->month;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    int getYear()
    {
        return this->year;
    }
    bool is_Leap_year(int year)
    {
        if ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0)
        {
            return true;
        }
        else
            return false;
    }
    void accept()
    {
        cout << "Enter the day = ";
        cin >> this->day;
        cout << "Enter the month = ";
        cin >> this->month;
        cout << "Enter the year = ";
        cin >> this->year;
        if (is_Leap_year(year) == true)
        {
            cout << year << " is a Leap Year " << endl;
        }
        else
            cout << year << " is Not a Leap Year " << endl;
    }
    void display()
    {
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
};

class Person
{
private:
    string name;
    string address;
    Date dob;

public:
    Person()
    {
        this->name = "";
        this->address = "";
    }
    Person(string name, string address, Date dob) : dob(dob)
    {
        this->name = name;
        this->address = address;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    string getAddress()
    {
        return this->address;
    }
    Date getBirthDate()
    {
        return this->dob;
    }
    void setBirthDate(Date dob)
    {
        this->dob = dob;
    }
    virtual void accept()
    {
        cout << "Enter the name = ";
        cin >> this->name;
        cout << "Enter the Address = ";
        cin >> this->address;
        cout << "Enter the DOB" << endl;
        dob.accept();
    }
    virtual void display()
    {
        cout << this->name << "  : " << this->address << endl;
        cout << "Date of birth = ";
        dob.display();
    }
};

class Employee : public Person
{
private:
    int eid;
    int salary;
    string dept;
    Date doj;

public:
    Employee()
    {
        this->eid = 0;
        this->salary = 0;
        this->dept = "";
    }
    Employee(string name, string address, Date doj, int eid, int salary, string dept, Date dob) : Person(name, address, dob)
    {
        this->setName(name);
        this->setAddress(address);
        // this->setDoj(doj);
        this->doj = doj;
        this->eid = eid;
        this->salary = salary;
        this->dept = dept;
        this->setBirthDate(dob);
    }

    void setEid(int eid)
    {
        this->eid = eid;
    }
    int getEid()
    {
        return this->eid;
    }
    void setSalary(int salary)
    {
        this->salary = salary;
    }
    int getSalary()
    {
        return this->salary;
    }
    void setDept(string dept)
    {
        this->dept = dept;
    }
    string getDept()
    {
        return this->dept;
    }
    void setDoj(Date doj)
    {
        this->doj = doj;
    }
    Date getDoj()
    {
        return this->doj;
    }
    void accept()
    {
        // Person::accept();
        cout << "Enter empid = ";
        cin >> this->eid;
        cout << "Enter salary = ";
        cin >> this->salary;
        cout << "Enter department = ";
        cin >> this->dept;
        cout << "Enter Date Of joining = " << endl;
        doj.accept();
    }
    void display()
    {
        Person::display();
        cout << "Empid = " << this->eid << endl;
        cout << "salary = " << this->salary << endl;
        cout << "dept = " << this->dept << endl;
        cout << "Date of joining = ";
        doj.display();
    }
};

int main()
{
    Person *ptr = new Employee(); // upcasting
    // ptr->accept();
    // ptr->display();
    // Employee *eptr=(Employee *) ptr; //downcasting
    // eptr->accept();
    // eptr->display();
    // Employee e;
    Date joining(12, 5, 2005);
    Date birth(14, 4, 8000);
    Employee e1("Dan", "karad", joining, 2, 5000, "kk", birth);
    e1.display();
    return 0;
}