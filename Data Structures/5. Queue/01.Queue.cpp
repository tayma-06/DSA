#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }
    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
    }

    void dequeue()
    {
        if (head == NULL)
        {
            cout << "Invalid. Empty Queue." << endl;
            return;
        }
        else if (head == tail)
        {
            head = tail = NULL;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty. Invalid Operation." << endl;
        }
        return head->data;
    }

    bool isEmpty()
    {
        return head == NULL ? true : false;
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