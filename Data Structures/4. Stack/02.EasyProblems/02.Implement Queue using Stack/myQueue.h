#include <iostream>
#include <stack>
using namespace std;

class myQueue
{
public:
    stack<int> st1, st2;

    void enqueue(int x)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    void dequeue()
    {
        if (!st1.empty())
        {
            st1.pop();
        }
    }

    int front()
    {
        if (!st1.empty())
            return st1.top();
        return -1;
    }

    int size()
    {
        return st1.size();
    }
};
