/*Q2. Write a class to store Account information of Bank customer by using following class diagram.
Use enum to store information of account type. Create an array of 5 Accounts in main() and accept
their details from user. Write Menu driven program to deposit/withdraw amount from the account.
After each transaction display updated account balance. Provide appropriate getters/setters with
necessary validations. Throw exceptions for invalid values. Also implement an exception class
InsufficientFunds. In withdraw() member function, if sufficient balance is not available
in account, throw this exception.*/
#include <iostream>
using namespace std;

class InsufficientFunds
{
private:
    int accid;
    double cur_balance;
    double withdraw_amount;

public:
    InsufficientFunds(int accid, double cur_balance, double withdraw_amount)
    {
        this->accid = accid;
        this->cur_balance = cur_balance;
        this->withdraw_amount = withdraw_amount;
    }
    void display()
    {
        cout << "Insufficient balance" << endl;
        cout << "Account-ID-" << this->accid << endl;
        cout << "Current available balance is: " << this->cur_balance << endl;
        cout << "Withdrawal requested amount is: " << this->withdraw_amount << endl;
    }
};
enum AccountType
{
    SAVING = 1,
    CURRENT,
    DMAT
} type;

class Account
{
private:
    int id;
    AccountType type;
    double balance;

public:
    Account()
    {
        this->id = 0;
        this->balance = 0;
    }
    Account(int id, AccountType type)
    {
        this->id = id;
        this->type = type;
    }
    void accept()
    {
        cout << "Enter ID = ";
        cin >> id;
        if (this->id < 0)
        {
            throw "INVALID ID";
        }
        cout << "Enter Accounttype  (1. SAVING 2.CURRENT 3.DMAT)" << endl;
        int i;
        cin >> i;
        if (i > 3 || i < 1)
        {
            throw "INVALID TYPE";
        }
        if (i == 0)
        {
            this->type = SAVING;
        }
        if (i == 1)
        {
            this->type = CURRENT;
        }
        if (i == 2)
        {
            this->type = DMAT;
        }
        // int temp;
        // cout << "Enter Accounttype = " << endl;
        // cout << "1. SAVING" << endl;
        // cout << "2. for CURRENT" << endl;
        // cout << "3. for DMAT" << endl;
        // cin >> temp;
        // this->type = AccountType(temp);
        // cout << "Enter id = ";
        // cin >> id;
        cout << "Enter account balance";
        cin >> balance;
        if (this->balance < 0)
        {
            throw "Invalid balance";
        }
    }
    void display()
    {
        cout << " Your Accoutnt Type = " << type << endl;
        cout << "Account ID = " << id << endl;
        cout << "Account Balance = " << balance << " /-RS " << endl;
    }
    void setType(AccountType type)
    {
        this->type = type;
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
    AccountType getType()
    {
        return this->type;
    }
    double getBalance()
    {
        return this->balance;
    }
    void deposit(double Amount)
    {
        balance = balance + Amount;
        cout << "Deposited Successfully !!!" << endl;
    }
    void withdraw(double Amount)
    {
        if (Amount > this->balance)

            throw InsufficientFunds(id, balance, Amount);
        else
            balance = balance - Amount;
        cout << "Withdrawal Successfull" << endl;
        cout << "Your Current Balance is " << balance << " /-RS " << endl;
    }
};

enum Menu
{
    EXIT,
    ACCEPT,
    DEPOSIT,
    WITHDRAW,
    DISPLAY

};
Menu menu_driven()
{
    int choice;
    cout << "-------------------" << endl;
    cout << "0. Exit. " << endl;
    cout << "1. ACCEPT. " << endl;
    cout << "2. DEPOSIT. " << endl;
    cout << "3. WITHDRAW. " << endl;
    cout << "4. DISPLAY.  " << endl;
    cout << "   Enter your choice :- ";
    cin >> choice;
    cout << "-----------------------------" << endl;
    return Menu(choice);
}
int main()
{
    Account *arr = new Account[2];
    int choice;
    int Amount;
    while ((choice = menu_driven()) != 0)
    {
        switch (choice)
        {
        case ACCEPT:
            for (int i = 0; i < 2; i++)
            {
                try
                {
                    arr[i].accept();
                }
                catch (const char *e)
                {
                    cout << "ERROR ENTER VALID DETAILS " << endl;
                }
            }
            break;
        case DEPOSIT:
        {
            int id;
            cout << "Enter your Acount ID = " << endl;
            cin >> id;
            for (int i = 0; i < 2; i++)
            {
                if (arr[i].getId() == id)
                {
                    cout << "Enter Acount To Add = " << endl;
                    cin >> Amount;
                    arr[i].deposit(Amount);
                }
            }
        }
        break;
        case WITHDRAW:
        {
            int id;
            cout << "Enter your Acount ID = " << endl;
            cin >> id;
            for (int i = 0; i < 2; i++)
            {
                if (arr[i].getId() == id)
                {
                    cout << "Enter Amount To Withdraw = " << endl;
                    cin >> Amount;
                    try
                    {
                        arr[i].withdraw(Amount);
                    }
                    catch (InsufficientFunds f)
                    {
                        f.display();
                    }
                }
            }
        }
        break;
        case DISPLAY:
            for (int i = 0; i < 2; i++)
            {
                arr[i].display();
            }
        default:
            break;
        }
    }
}