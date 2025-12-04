#include <bits/stdc++.h>
using namespace std;

class priorityQueue
{
    static const int MAXP = 5;
    queue<int> pq[MAXP];

public:
    bool isEmpty()
    {
        for (int i = 0; i < MAXP; i++)
        {
            if (!pq[i].empty())
                return false;
        }
        return true;
    }

    void enqueue(int val, int prio)
    {
        if (prio < 0 || prio >= MAXP)
        {
            cout << "Invalid priority\n";
            return;
        }
        pq[prio].push(val);
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty\n";
            return;
        }

        for (int i = 0; i < MAXP; i++)
        {
            if (!pq[i].empty())
            {
                pq[i].pop();
                return;
            }
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "The queue is empty\n";
            return -1;
        }
        for (int i = 0; i < MAXP; i++)
        {
            if (!pq[i].empty())
                return pq[i].front();
        }

        return -1;
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "The queue is empty\n";
            return -1;
        }
        for (int i = MAXP - 1; i >= 0; i--)
        {
            if (!pq[i].empty())
                return pq[i].back();
        }
        return -1;
    }

    void display()
    {
        for (int i = 0; i < MAXP; i++)
        {
            queue<int> temp = pq[i];
            cout << "Priority " << i << ": ";
            while (!temp.empty())
            {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }

    int sizeOf()
    {
        int size = 0;
        for (int i = 0; i < MAXP; i++)
        {
            size += pq[i].size();
        }
        return size;
    }
};

int main()
{
    priorityQueue pq;
    pq.enqueue(10, 3);
    pq.enqueue(20, 1);
    pq.enqueue(30, 2);
    pq.enqueue(40, 1);
    pq.enqueue(50, 4);
    pq.display();
    cout << endl;
    pq.dequeue();
    pq.display();
    cout << endl;
    cout << "Front: " << pq.getFront() << endl;
    cout << "Rear: " << pq.getRear() << endl;
    cout << "Size: " << pq.sizeOf() << endl;

    return 0;
}
