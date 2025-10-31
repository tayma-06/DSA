#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v[v.size() - 1];
    }
    bool empty()
    {
        return v.size() == 0 ? true : false;
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