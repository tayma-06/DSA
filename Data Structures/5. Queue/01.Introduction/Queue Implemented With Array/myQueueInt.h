// Implemented queue using array
#include <iostream>
using namespace std;

class myQueue
{
    int *arr;
    int capacity;
    int front;
    int size;

public:
    myQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
    }

    void enqueue(int val)
    {
        if (size == capacity)
        {
            cout << "Queue is Overloaded." << endl;
            return;
        }
        arr[size++] = val;
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is Underoaded." << endl;
            return;
        }
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    int getFront()
    {
        if (size == 0)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[0];
    }

    int getRear()
    {
        if (size == 0)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[size - 1];
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0 ? true : false;
    }

    bool isFull()
    {
        return size == capacity - 1 ? true : false;
    }
};