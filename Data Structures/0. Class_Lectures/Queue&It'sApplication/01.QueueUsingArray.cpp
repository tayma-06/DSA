#include <bits/stdc++.h>
using namespace std;

class myQueue
{
    int *arr;
    int size;
    int capacity;

public:
    myQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }
    void enqueue(int val)
    {
        if (size == capacity)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[size++] = val;
    }
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
    }
    int getFront()
    {
        return arr[0];
    }
    int getRear()
    {
        return arr[size - 1];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    myQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.enqueue(6);

    q.dequeue();
    q.display();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
}