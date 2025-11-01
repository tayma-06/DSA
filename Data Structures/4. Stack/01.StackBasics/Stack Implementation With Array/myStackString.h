// Implementation Of Stack using Array
#include <iostream>
#include <string>
using namespace std;

class myStack
{
    string *arr;
    int capacity;
    int top;

public:
    myStack(int cap)
    {
        capacity = cap;
        arr = new string[capacity];
        top = -1;
    }

    void push(string val)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    string peek()
    {
        return arr[top];
    }

    int size()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        return top + 1;
    }

    bool isFull()
    {
        return top == capacity - 1 ? true : false;
    }

    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
};