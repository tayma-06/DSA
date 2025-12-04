#include <bits/stdc++.h>
using namespace std;

class myCircularQueue
{
    int *arr;
    int capacity;
    int size;
    int front;

public:
    myCircularQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
        front = 0;
    }

    void enqueue(int val)
    {
        if (size == capacity)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        int rear = (front + size) % capacity;
        arr[rear] = val;
        size++;
    }

    int dequeue()
    {
        if (size == 0)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int result = arr[front];
        front = (front + 1) % capacity;
        size--;
        return result;
    }

    int sizeOf()
    {
        return size;
    }

    int getFront()
    {
        if (sizeOf() == 0)
        {
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (sizeOf() == 0)
        {
            return -1;
        }
        return arr[(front + size) % capacity];
    }
    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    myCircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.enqueue(6);

    q.dequeue();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Size of the queue: " << q.sizeOf() << endl;
}