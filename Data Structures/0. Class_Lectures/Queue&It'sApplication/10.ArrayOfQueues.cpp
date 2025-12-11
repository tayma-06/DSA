#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    queue<int> priorityList[6];

public:
    bool isEmpty()
    {
        for (int i = 0; i < 6; i++)
        {
            if (!priorityList[i].empty())
                return false;
        }
        return true;
    }

    void enqueue(int value, int priority)
    {
        if (priority < 0 || priority >= 6)
        {
            cout << "Invalid priority level" << endl;
            return;
        }
        priorityList[priority].push(value);
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = 0; i < 6; i++)
        {
            if (!priorityList[i].empty())
            {
                priorityList[i].pop();
                return;
            }
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        for (int i = 0; i < 6; i++)
        {
            if (!priorityList[i].empty())
                return priorityList[i].front();
        }
        return -1;
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        for (int i = 5; i >= 0; i--)
        {
            if (!priorityList[i].empty())
                return priorityList[i].back();
        }
        return -1;
    }

    void display()
    {
        for (int i = 0; i < 6; i++)
        {
            cout << "Priority " << i << ": ";
            queue<int> temp = priorityList[i];

            while (!temp.empty())
            {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }

    int totalSize()
    {
        int total = 0;
        for (int i = 0; i < 6; i++)
            total += priorityList[i].size();
        return total;
    }
};

int main()
{
    PriorityQueue pq;

    pq.enqueue(10, 3);
    pq.enqueue(20, 1);
    pq.enqueue(30, 2);
    pq.enqueue(40, 1);
    pq.enqueue(50, 5);

    pq.display();
    cout << endl;

    pq.dequeue();
    pq.display();

    cout << "Front: " << pq.getFront() << endl;
    cout << "Rear: " << pq.getRear() << endl;
    cout << "Total Size: " << pq.totalSize() << endl;

    return 0;
}
