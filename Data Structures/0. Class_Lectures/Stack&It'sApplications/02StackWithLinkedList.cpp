#include <bits/stdc++.h>
using namespace std;

class myStack
{
    list<int> ll;

public:
    myStack()
    {
    }

    void push(int val)
    {
        ll.push_front(val);
    }

    void pop()
    {
        ll.pop_front();
    }

    void display()
    {
        for (int i : ll)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    myStack stack;
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