/*Q2. Implement following classes. Test all functionalities in main() of each created class. Note that
employee is inherited into manager and salesman. Insted of char[] use string datatype.*/

#include <iostream>

using namespace std;

class Employee
{
private:
    int eid;
    float salary;

public:
    Employee()
    {
        cout << "cotr of Employee " << endl;
        this->eid = 0;
        this->salary = 0;
    }
    Employee(int eid, float salary)
    {
        this->eid = eid;
        this->salary = salary;
    }
    int getEid()
    {
        return this->eid;
    }
    void setEid(int eid)
    {
        this->eid = eid;
    }
    float getSalary()
    {
        return this->salary;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    void accept()
    {
        cout << "Enter empid = ";
        cin >> eid;
        cout << "Enter Salary = ";
        cin >> salary;
    }
    void display()
    {
        cout << " empid = " << eid << endl;
        cout << "salary = " << salary << endl;
    }
};

class Manager : virtual public Employee
{
private:
    float bonus;

public:
    Manager()
    {
        this->bonus = 0;
        cout << "cotr of Manager " << endl;
    }
    Manager(int eid, float salary, float bonus)
    {
        Employee::setEid(eid);
        Employee::setSalary(salary);
        this->bonus = bonus;
    }
    float getBonus()
    {
        return this->bonus;
    }
    void setBonus(float bonus)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        Employee::accept();
        cout << "Enter bonus";
        cin >> bonus;
    }
    void display()
    {
        Employee::display();
        cout << "Bonus = " << bonus << endl;
    }

protected:
    void accept_Manager()
    {
        cout << "Bonus = ";
        cin >> bonus;
    }
    void display_Manager()
    {
        cout << " bonus is = " << bonus << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    float comm;

public:
    Salesman()
    {
        cout << "cotr of Salesman " << endl;
        this->comm = 0;
    }
    Salesman(int eid, float salary, float comm)
    {
        Employee::setEid(eid);
        Employee::setSalary(salary);
        this->comm = comm;
    }
    void setComm(float comm)
    {
        this->comm = comm;
    }
    float getComm()
    {
        return this->comm;
    }
    void accept()
    {
        Employee::accept();
        cout << "Enter commission = ";
        cin >> comm;
    }
    void display()
    {
        Employee::display();
        cout << "Commission is = " << comm << endl;
    }

protected:
    void accept_Salesman()
    {
        cout << "comm = ";
        cin >> comm;
    }
    void display_Salesman()
    {
        cout << " Comm is = " << comm << endl;
    }
};

class Sales_Manager : public Manager, public Salesman
{
public:
    Sales_Manager()
    {
        cout << "cotr of Sales_Manager " << endl;
    }
    Sales_Manager(int eid, float salary, float bonus, float comm)
    {
        Employee::setEid(eid);
        Employee::setSalary(salary);
        Manager::setBonus(bonus);
        Salesman::setComm(comm);
    }
    void accept()
    {
        Manager::accept_Manager();
        Salesman::accept();
    }
    void display()
    {
        Manager::display();
        Salesman::display();
    }
};
int main()
{
    Sales_Manager s1;
    // s1.accept_Manager();
    s1.accept();
    s1.display();
}