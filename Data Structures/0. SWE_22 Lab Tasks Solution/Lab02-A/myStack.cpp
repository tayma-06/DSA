// myStack.cpp file
#include <iostream>
#include "SingleList.h"
using namespace std;

class myStack
{
    List list;

public:
    void push(int val)
    {
        list.pushFront(val);
    }

    void pop()
    {
        list.popFront();
    }

    int top()
    {
        return list.getHead();
    }

    int size()
    {
        return list.size();
    }

    bool empty()
    {
        return list.size() == 0 ? true : false;
    }
};

int main()
{
    myStack stack;
    stack.push(4);
    stack.push(3);
    stack.push(2);

    cout << "Data: " << endl;
    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }

    return 0;
}