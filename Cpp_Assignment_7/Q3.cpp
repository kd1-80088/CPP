/*Q3. Using the Q1 from assignment 6. Create an array of 10 employees. Provide menu driven code
for the functionalities: Insted of char[] use string datatype
1. Accept Employee
2. Display the count of all employees with respect to
designation
3. Display respective designation employees*/

#include <iostream>
using namespace std;
class Employee
{
private:
    int eid;
    float salary;
    string designation;

public:
    Employee()
    {
        cout << "cotr of Employee " << endl;
        this->eid = 0;
        this->salary = 0;
        this->designation = "";
    }
    Employee(int eid, float salary, string designation)
    {
        this->eid = eid;
        this->salary = salary;
        cout << "Designation ";
        cin >> designation;
        this->designation = designation;
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
    string getDesignation()
    {
        return this->designation;
    }
    void setDesignation(string designation)
    {
        this->designation = designation;
    }
    virtual void accept()
    {
        cout << "Enter empid = ";
        cin >> eid;
        cout << "Enter Salary = ";
        cin >> salary;
        cout << "Designation =";
        cin >> designation;
    }
    virtual void display()
    {
        cout << " empid = " << eid << endl;
        cout << "salary = " << salary << endl;
        cout << " Designation = " << designation << endl;
    }
    virtual ~Employee()
    {
    }
};

class Manager : virtual public Employee
{
private:
    float bonus;

public:
    Manager()
    {
        this->setDesignation("Manager");
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
        cin >> this->bonus;
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
        this->comm = 0;
        this->setDesignation("salesman");
    }
    Salesman(int eid, float salary, float comm)
    {

        Employee::setEid(eid);       // this or base class
        Employee::setSalary(salary); // this or base class
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
        this->setDesignation("salesmanager");
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
        Employee::accept();
        Manager::accept_Manager();
        Salesman::accept_Salesman();
    }
    void display()
    {
        Employee::display();
        Manager::display_Manager();
        Salesman::display_Salesman();
    }
};

enum Menu
{
    EXIT,
    ACCEPTMANAGER,
    ACCEPTSALESMAN,
    ACCEPTSALESMANAGER,
    DISPLAYMANAGER,
    DISPLAYSALESMAN,
    DISPLAYSALESMANAGER,
    DISPLAYEMPLOYEE,
    MANAGERCOUNT,
    SALESMANCOUNT,
    SALESMANAGERCOUNT
};
Menu menu_driven()
{
    int choice;
    cout << "------------------------" << endl;
    cout << "0. Exit.             " << endl;
    cout << "1. ACCEPTMANAGER.      " << endl;
    cout << "2. ACCEPTSALESMAN.     " << endl;
    cout << "3. ACCEPTSALESMANAGER. " << endl;
    cout << "4. DISPLAYMANAGER.     " << endl;
    cout << "5. DISPLAYSALESMAN.   " << endl;
    cout << "6. DISPLAYSALESMANAGER." << endl;
    cout << "7. DISPLAYEMPLOYEE.   " << endl;
    cout << "8. COUNTEMANAGER       " << endl;
    cout << "9. COUNTESALESMAN      " << endl;
    cout << "10. COUNTESALESMANAGER " << endl;
    cout << "Enter your choice :- ";
    cin >> choice;
    cout << "-----------------------------" << endl;
    return Menu(choice);
}
Menu menu()
{
    int choiice;
    cout << "*******************************" << endl;
    cout << "MANAGER_COUNT 1. " << endl;
    cout << "Salesman_COUNT 2. " << endl;
    cout << "SalesManager_COUNT 3. " << endl;
    cout << "*******************************" << endl;
    cin >> choiice;
    return Menu(choiice);
}
// void countDesignation(Employee *arr[], int index)
// {
//     int s = 0, m = 0, sm = 0;
//     for (int i = 0; i < index; i++)
//     {
//         if (arr[i]->getDesignation() == "manager")
//         {
//             m++;
//         }
//         else if (arr[i]->getDesignation() == "salesman")
//         {
//             s++;
//         }
//         else if (arr[i]->getDesignation() == "salesmanager")
//         {
//             sm++;
//         }
//     }
// }

int main()
{
    Employee *arr[10];
    int m = 0, s = 0, sm = 0;
    int index = 0;
    int choice;
    while ((choice = menu_driven()) != 0)
    {
        switch (choice)
        {
        case ACCEPTMANAGER:
            if (index < 10)
            {
                arr[index] = new Manager();
                arr[index]->accept();
                index++;
            }
            else
                cout << "Array is full we cannot hire Manager " << endl;
            break;
        case ACCEPTSALESMAN:
            if (index < 10)
            {
                arr[index] = new Salesman();
                arr[index]->accept();
                index++;
            }
            else
                cout << "Array is full we cannot hire Salesman " << endl;
            break;
        case ACCEPTSALESMANAGER:
            if (index < 10)
            {
                arr[index] = new Sales_Manager();
                arr[index]->accept();
                index++;
            }
            else
                cout << "Array is full we cannot hire Sales_Manager " << endl;
            break;
        case DISPLAYMANAGER:

            for (int i = 0; i < index; i++)

            {
                if (arr[i]->getDesignation() == "manager")
                {
                    arr[i]->display();
                }
            }
            break;
        case DISPLAYSALESMAN:

            for (int i = 0; i < index; i++)
            {
                if (arr[i]->getDesignation() == "salesman")
                {
                    arr[i]->display();
                }
            }
            break;
        case DISPLAYSALESMANAGER:

            for (int i = 0; i < index; i++)
            {
                if (arr[i]->getDesignation() == "salesmanager")
                {
                    arr[i]->display();
                }
            }
            break;
        case DISPLAYEMPLOYEE:
            for (int i = 0; i < index; i++)
            {
                arr[i]->display();
            }
            break;
        case MANAGERCOUNT:
            for (int i = 0; i < index; i++)
            {
                if (arr[i]->getDesignation() == "manager")
                {
                    m++;
                }
            }
            cout << "count of Manager = " << m << endl;
            break;
        case SALESMANCOUNT:
            for (int i = 0; i < index; i++)
            {
                if (arr[i]->getDesignation() == "salesman")
                {
                    s++;
                }
            }
            cout << "count of Salesman = " << s << endl;
            break;
        case SALESMANAGERCOUNT:
            for (int i = 0; i < index; i++)
            {
                if (arr[i]->getDesignation() == "salesmanager")
                {
                    sm++;
                }
            }
            cout << "count of SalesManager = " << sm << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }

    for (int i = 0; i < index; i++)
    {
        delete arr[i];

        cout << "Done!!!" << endl;
    }
}