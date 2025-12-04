#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    int priority;
    Node(int val, int prio)
    {
        data = val;
        priority = prio;
        next = NULL;
    }
};

class priorityQueue
{
    Node *head;
    Node *tail;

public:
    priorityQueue()
    {
        head = tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(int val, int prio)
    {
        Node *newNode = new Node(val, prio);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        if (prio < head->priority)
        {
            newNode->next = head;
            head = newNode;
        }
        else if (prio >= tail->priority)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL && temp->next->priority <= prio)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail == NULL;
        }
        delete temp;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
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
    priorityQueue pq;
    pq.enqueue(10, 3);
    pq.enqueue(20, 1);
    pq.enqueue(30, 2);
    pq.enqueue(40, 1);
    pq.enqueue(50, 4);
    pq.display();
    pq.dequeue();
    pq.display();
    cout << "Front: " << pq.getFront() << endl;
    cout << "Rear: " << pq.getRear() << endl;
    cout << "Size: " << pq.sizeOf() << endl;
    return 0;
}