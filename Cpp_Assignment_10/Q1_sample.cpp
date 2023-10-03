/*Q1. Implement a Stack class using C++ templates. Test stack operations on Stack<int>,
Stack<double> and Stack<Box>.*/
#include <iostream>
using namespace std;

class Box
{
private:
    int length;
    int width;
    int height;

public:
    Box()
    {
        this->length;
        this->width;
        this->height;
    }
    Box(int length, int width, int height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }
    void acceptValues()
    {
        cout << "length is = ";
        cin >> length;
        cout << "width is = ";
        cin >> width;
        cout << "heigth is = ";
        cin >> height;
    }
    int calculateVolume()
    {
        return this->length * this->width * this->height;
    }
    void displayVolume()
    {
        cout << "Volume = " << calculateVolume() << endl;
    }
};

template <class T>
class Stack
{
private:
    T *arr;
    int size;
    int top;
    // T element;

public:
    Stack()
    {
        this->arr = new T[this->size];
        this->size = 5;
        this->top = -1;
        // this->element;
    }
    Stack(int size)
    {
        this->arr = new T[this->size];
        this->size = size;
        this->top = -1;
    }
    void push(T element)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = element;
        }
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Underflow" << endl;
        }
        else
        {
            cout << "element at top = "
                 << " [" << top << "]  :" << arr[top] << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Underflow" << endl;
        }
        else
        {
            arr[top] = 0;
            top--;
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << " elemnets at "
                 << "[ " << i << " ]"
                 << " : " << arr[i] << endl;
        }
    }
    int getLength()
    {
        return this->top;
    }
    ~Stack()
    {
        delete[] this->arr;
    }
};

enum Menu
{
    EXIT,
    ACCEPT,
    DISPLAY,
    CALCULATE
};
Menu menu_driven()
{
    int choice;
    cout << "-------------------" << endl;
    cout << " Exit. 0" << endl;
    cout << "ACCEPT. 1 " << endl;
    cout << "DISPLAY. 2 " << endl;
    cout << "CALCULATE. 3 " << endl;
    cout << "Enter your choice :- ";
    cin >> choice;
    cout << "-----------------------------" << endl;
    return Menu(choice);
}
int main()
{
    int choice;

    Stack<Box *> s1;
    Box *b = new Box();
    b->acceptValues();
    b->calculateVolume();
    b->displayVolume();
    s1.push(b);
    // s1.print();
    // while ((choice = menu_driven()) != 0)
    // {
    //     switch (choice)
    //     {
    //     case ACCEPT:
    //     {
    //         Box b;
    //         b.acceptValues();
    //         s1.push(b);

    //     }
    //     break;
    //     case DISPLAY:
    //     {
    //         Box b;

    //     }
    //     break;
    //     case CALCULATE:
    //     {
    //         Box b;
    //         b.calculateVolume();
    //     }
    //     break;
    //     default:
    //         cout << "Wrong Choice " << endl;
    //         break;
    //     }
    // }

    // Stack<char> s1;
    // s1.push('A');
    // s1.push('B');
    // s1.push('C');
    // s1.push('D');
    // s1.push('E');
    // s1.pop();
    // s1.push('F');
    // s1.peek();
    // s1.print();

    // Stack<int> s1;
    // s1.push(10);
    // s1.push(20);
    // s1.push(10);
    // s1.push(20);
    // s1.push(10);
    // s1.pop();
    // s1.push(20);
    // s1.peek();
    // s1.print();
}
