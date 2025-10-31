#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int currentSize, capacity;
    int front, rear;

public:
    CircularQueue(int size)
    {
        arr = new int[size];
        capacity = size;
        currentSize = 0;
        front = 0;
        rear = -1;
    }

    void push(int val)
    {
        if (currentSize == capacity)
        {
            cout << "Queue Full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        currentSize++;
    }

    void pop()
    {
        if (currentSize == 0)
        {
            cout << "Queue Empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        currentSize--;
    }

    int getFront()
    {
        return arr[front];
    }

    int size()
    {
        return currentSize;
    }

    bool empty()
    {
        return currentSize == 0 ? true : false;
    }
};