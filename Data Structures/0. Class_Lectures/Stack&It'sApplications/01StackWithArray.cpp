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
    }
};

int main()
{

    return 0;
}