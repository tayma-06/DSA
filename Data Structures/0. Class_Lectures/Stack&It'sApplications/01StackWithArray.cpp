#include <bits/stdc++.h>
using namespace std;

class myStack
{
    int *arr;
    int capacity;
    int top;

public:
    myStack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    void push(int val)
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

    int peek()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }

    bool full()
    {
        return top == capacity - 1;
    }

    void display()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    myStack stack(10);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    stack.display();

    stack.pop();
    stack.pop();

    stack.display();

    return 0;
}