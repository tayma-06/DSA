#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int size, capacity, front, rear;

public:
    Queue(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }
    void push(int val)
    {
        if(full())
        {
            cout << "Full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }
    void pop()
    {
        if(empty())
        {
            cout << "Empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }
    int frontVal()
    {
        return arr[front];
    }
    int rearVal()
    {
        return arr[rear];
    }
    int sizeOf()
    {
        return size;
    }
    bool full()
    {
        return size == capacity;
    }
    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    int capacity;
    cin >> capacity;
    Queue q(capacity);
    while(true)
    {
        int choice, value;
        cin >> choice;
        if(choice == 0)
        {
            break;
        }
        switch(choice)
        {
            case 1:
                cin >> value;
                q.push(value);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                cout << q.frontVal() << endl;
                break;
            case 4:
                cout << q.rearVal() << endl;
                break;
            case 5:
                cout << q.sizeOf() << endl;
                break;
            default:
                cout << "Invalid Operation" << endl;
                break;
        }
    }
}