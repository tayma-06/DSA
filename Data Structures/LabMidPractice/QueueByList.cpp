#include <bits/stdc++.h>
using namespace std;

class Queue
{
    list<int> ll;

public:
    void push(int val)
    {
        ll.push_back(val);
    }
    void pop()
    {
        ll.pop_front();
    }
    int front()
    {
        return ll.front();
    }
    bool empty()
    {
        return ll.empty();
    }
    int size()
    {
        return ll.size();
    }
};

int main()
{
    Queue q;
    while (true)
    {
        int choice, value;
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            cin >> value;
            q.push(value);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            cout << q.front() << endl;
            break;
        case 4:
            cout << q.size() << endl;
            break;
        default:
            cout << "Invalid Operation" << endl;
            break;
        }
    }
}
