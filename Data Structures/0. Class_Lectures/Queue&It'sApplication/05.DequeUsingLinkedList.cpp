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

class myDequeList
{
    Node *head;
    Node *tail;

public:
    myDequeList()
    {
        head = tail = NULL;
    }

    void insertFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void deleteFront()
    {
        if (head == NULL)
        {
            cout << "No element in the queue" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteBack()
    {
        if (head == NULL)
        {
            cout << "No element in the queue" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int isEmpty()
    {
        return head == NULL;
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

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->data;
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return tail->data;
    }
};

int main()
{
    myDequeList q;
    q.insertBack(7);
    q.insertFront(6);

    cout << q.getFront() << " " << q.getRear() << endl;
}