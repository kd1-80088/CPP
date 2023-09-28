/*Q1. Implement following classes. Test all functionalities in main().Insted of char[] use string
datatype*/
//Example of Association(composition)

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
    void acceptDate()
    {
        cout << "Enter the day = ";
        cin >> this->day;
        cout << "Enter the month = ";
        cin >> this->month;
        cout << "Enter the year = ";
        cin >> this->year;
        if(is_Leap_year(year)==true)
        {
            cout<<year<<" is a Leap Year "<<endl;
        }
        else
        cout<<year <<" is Not a Leap Year "<<endl;
        
    }
    void displayDate()
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
        this->name="";
        this->address="";
    }
    Person(string name,string address,int day,int month,int year):dob(day,month,year)
    {
        this->name=name;
        this->address=address;
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
    void acceptPerson()
    {
        cout << "Enter the name = ";
        cin >> this->name;
        cout << "Enter the Address = ";
        cin >> this->address;
        cout<<"Enter the DOB";
        dob.acceptDate();
    }
     void displayPerson()
    {
        cout << this->name << "  : " << this->address  << endl;
        cout << "Date of birth = ";
        dob.displayDate();
    }
};

class Employee
{
private:
    int eid;
    int salary;
    string dept;
    Date doj;
    Person person;

public:
    Employee()
    {
        this->eid = 0;
        this->salary = 0;
        this->dept = "";
    }
    Employee(int eid, int salary, string dept, int day, int month, int year,string name,string address) : doj(day, month, year),person(name,address,day,month,year)
    {
        this->eid = eid;
        this->salary = salary;
        this->dept = dept;
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
    void acceptEmployee()
    {
        cout << "Enter empid = ";
        cin >> this->eid;
        cout << "Enter salary = ";
        cin >> this->salary;
        cout << "Enter department = ";
        cin >> this->dept;
        cout << "Enter Date Of joining = " << endl;
        doj.acceptDate();
         cout << "Enter Date Of Birth = " << endl;
     
    }
    void displayEmployee()
    {
        cout << "Empid = " << this->eid << endl;
        cout << "salary = " << this->salary << endl;
        cout << "dept = " << this->dept << endl;
        cout << "Date of joining = ";
        doj.displayDate();

        // cout << "Date of Birth = ";
        //dob.displayDate();
    }
};

int main()
{
    //Date d1;
    Employee e1;
    e1.acceptEmployee();
    e1.displayEmployee();
    //e1.acceptD();
    
    //d1.acceptDate();
    //d1.displayDate();
    return 0;
}