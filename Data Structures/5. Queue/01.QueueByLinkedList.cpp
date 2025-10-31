#include <iostream>
#include <list>
using namespace std;

class Queue
{
    list<int> ll;

public:
    void enqueue(int val)
    {
        ll.push_back(val);
    }
    void dequeue()
    {
        ll.pop_front();
    }
    int front()
    {
        return ll.front();
    }
    bool isEmpty()
    {
        return ll.size() == 0 ? true : false;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Data in the Queue: " << endl;
    while (!q.isEmpty())
    {
        cout << q.front() << endl;
        q.dequeue();
    }
    return 0;
}