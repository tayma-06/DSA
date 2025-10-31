#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size)
    {
        cap = size;
        currSize = 0;
        arr = new int[cap];
        f = 0;
        r = -1;
    }

    void push(int val)
    {
        if (currSize == cap)
        {
            cout << "The Circular Queue is Full." << endl;
            return;
        }
        r = (r + 1) % cap;
        arr[r] = val;
        currSize++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "The Circular Queue is empty!" << endl;
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    int front()
    {
        return arr[f];
    }

    bool empty()
    {
        return currSize == 0 ? true : false;
    }
};

int main()
{
    CircularQueue queue(4);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    while (!queue.empty())
    {
        cout << queue.front() << endl;
        queue.pop();
    }

    return 0;
}