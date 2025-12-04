#include <bits/stdc++.h>
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
class myListQueue
{
    Node *head;
    Node *tail;

public:
    myListQueue()
    {
        head = tail = NULL;
    }

    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "No element in the queue" << endl;
            return -1;
        }
        return head->data;
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
            return -1;
        }
        return tail->data;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int sizeOf()
    {
        Node *temp = head;
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
};

int main()
{
    myListQueue q;
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
    cout << "Size of the queue: " << q.sizeOf() << endl;
}
