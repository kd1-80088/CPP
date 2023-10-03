/*Q2. A Product sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.*/

#include <iostream>

using namespace std;

class Product
{
protected:
    int id;
    string title;
    float price;
    string type;

public:
    Product()
    {
        this->id = 0;
        this->title = "";
        this->price = 0;
        this->type = "";
    }
    Product(int id, string title, float price, string type)
    {
        this->id = id;
        this->title = title;
        this->price = price;
        this->type = type;
    }
    void setType(string type)
    {
        this->type = type;
    }
    string getType()
    {
        return this->type;
    }
    float getPrice()
    {
        return this->price;
    }
    void setPrice(float price)
    {
        this->price = price;
    }
    virtual void addProduct()
    {
        cout << "Enter Id = ";
        cin >> id;
        cout << "Enter Title = ";
        cin >> title;
        cout << "Enter Price = ";
        cin >> price;
        cout << "Enter Type ";
        cin >> type;
    }
    virtual void addProduct() = 0;
    // friend void calculateBill(Product arr[]);
};
class Book : public Product
{
private:
    string author;

public:
    Book()
    {
        this->author = "";
        this->type = "B";
    }
    Book(string author)
    {
        this->author = author;
    }
    void addProduct()
    {
        Product::addProduct();
        cout << "Enter Book Author = ";
        cin >> author;
    }
};

class Tape : public Product
{
private:
    string artist;

public:
    Tape()
    {
        this->artist = "";
        this->type = "T";
    }
    Tape(string artist)
    {
        this->artist = artist;
    }
    void addProduct()
    {
        Product::addProduct(); // Implement using abstract class without calling base class method
        cout << "Enter Tape artist = ";
        cin >> artist;
    }
};

void calculateBill(Product **arr, int index)
{
    int c = 0, d = 0;
    int Book_count = 0;
    int Tape_count = 0;
    for (int i = 0; i < index; i++)
    {
        if (arr[i]->getType() == "B")
        {
            c += arr[i]->getPrice() * 0.90;
            Book_count++;
        }
    }
    // cout << "Total BOOK Bill =" << c << endl;
    for (int i = 0; i < index; i++)
    {
        if (arr[i]->getType() == "T")
        {
            d += arr[i]->getPrice() * 0.95;
            Tape_count++;
        }
    }
    cout << "Total TAPE Bill = " << c + d << endl;
    cout << "Total Book count = " << Book_count << endl;
    cout << "Total TAPE count = " << Tape_count << endl;
}
enum Menu
{
    EXIT,
    ADDBOOK,
    ADDTAPE,
    CALCULATEBILL,
    DISPLAY

};
Menu menu_driven()
{
    int choice;
    cout << "-------------------" << endl;
    cout << " Exit. 0" << endl;
    cout << "ADDBOOK. 1 " << endl;
    cout << "ADDTAPE. 2 " << endl;
    cout << "CALCULATEBILL. 3 " << endl;
    cout << "Enter your choice :- ";
    cin >> choice;
    cout << "-----------------------------" << endl;
    return Menu(choice);
}
int main()
{
    Product *arr[3];
    // Product *p1;
    int index = 0;
    int choice;
    while ((choice = menu_driven()) != 0)
    {
        switch (choice)
        {
        case ADDBOOK:
            if (index < 3)
            {
                arr[index] = new Book();
                arr[index]->addProduct();
                index++;
            }
            else
                cout << "Array is full we cannot add Book " << endl;
            break;
        case ADDTAPE:
            if (index < 3)
            {
                arr[index] = new Tape();
                arr[index]->addProduct();
                index++;
            }
            else
                cout << "Array is full we cannot add Tape " << endl;
            break;
        case CALCULATEBILL:
            calculateBill(arr, index);
            break;

        default:
            break;
            cout << "Entered Wrong Product !!!" << endl;
        }
    }

    cout << "Thank you Visit again!!!" << endl;

    return 0;
}
