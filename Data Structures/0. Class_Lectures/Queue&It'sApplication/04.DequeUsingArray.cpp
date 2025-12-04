#include <bits/stdc++.h>
using namespace std;

class myDeque
{
    int *arr;
    int capacity;
    int front;
    int size;

public:
    myDeque(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
    }

    void insertFront(int val)
    {
        if (size == capacity)
        {
            cout << "The queue is full" << endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = val;
        size++;
    }

    void insertBack(int val)
    {
        if (size == capacity)
        {
            cout << "The queue is full" << endl;
            return;
        }
        int rear = (front + size) % capacity;
        arr[rear] = val;
        size++;
    }

    int deleteFront()
    {
        if (size == 0)
        {
            cout << "The queue is empty" << endl;
            return -1;
        }
        int result = (front + 1) % capacity;
        size--;
        return result;
    }

    int deleteBack()
    {
        if (size == 0)
        {
            cout << "The queue is empty" << endl;
            return -1;
        }
        int rear = (front + size - 1) % capacity;
        int result = arr[rear];
        size--;
        return result;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
            return -1;
        }
        return arr[(front + size - 1) % capacity];
    }

    int sizeOf()
    {
        return size;
    }

    int isEmpty()
    {
        return size == 0;
    }

    int isFull()
    {
        return size == capacity;
    }
};

int main()
{
    myDeque q(6);
    q.insertBack(7);
    q.insertFront(6);

    cout << q.getFront() << " " << q.getRear() << endl;
}