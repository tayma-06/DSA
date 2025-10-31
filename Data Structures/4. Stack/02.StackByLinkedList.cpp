#include <iostream>
#include <list>
using namespace std;

class Stack
{
    list<int> ll;

public:
    void push(int val)
    {
        ll.push_front(val);
    }
    void pop()
    {
        ll.pop_front();
    }
    int top()
    {
        return ll.front();
    }
    bool empty()
    {
        return ll.size() == 0 ? true : false;
    }
};

int main()
{
    Stack stack;
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