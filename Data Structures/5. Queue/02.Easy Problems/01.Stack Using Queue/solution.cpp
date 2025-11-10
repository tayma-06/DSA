#include <iostream>
#include <queue>
using namespace std;

class myStack
{
    queue<int> q;

public:
    void push(int x)
    {
        queue<int> q2;
        q2.push(x);
        while (!q.empty())
        {
            q2.push(q.front());
            q.pop();
        }
        while (!q2.empty())
        {
            q.push(q2.front());
            q2.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            return;
        }
        q.pop();
    }

    int top()
    {
        if (q.empty())
        {
            return -1;
        }
        return q.front();
    }

    int size()
    {
        return q.size();
    }
};

int main()
{
    myStack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Popped: " << st.top() << endl;
    st.pop();

    cout << "Top element: " << st.top() << endl;

    cout << "Current size: " << st.size() << endl;

    return 0;
}
