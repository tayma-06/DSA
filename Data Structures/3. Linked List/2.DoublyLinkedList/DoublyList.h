#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void push(int val, int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 1)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        int currentPos = 1;

        while (temp != NULL && currentPos < pos - 1)
        {
            temp = temp->next;
            currentPos++;
        }

        if (temp == NULL)
        {
            push_back(val);
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;
        else
            tail = newNode;

        temp->next = newNode;
    }

    void delete_front()
    {
        if (isEmpty())
        {
            cout << "List is empty!\n";
            return;
        }

        Node *temp = head;

        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    void delete_back()
    {
        if (isEmpty())
        {
            cout << "List is empty!\n";
            return;
        }

        Node *temp = tail;

        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
    }

    void delete_pos(int pos)
    {
        if (isEmpty())
        {
            cout << "List is empty!\n";
            return;
        }

        if (pos <= 0)
        {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 1)
        {
            delete_front();
            return;
        }

        Node *temp = head;
        int currentPos = 1;

        while (temp != NULL && currentPos < pos)
        {
            temp = temp->next;
            currentPos++;
        }

        if (temp == NULL)
        {
            cout << "Position out of range\n";
            return;
        }

        if (temp == tail)
        {
            delete_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void delete_value(int val)
    {
        if (isEmpty())
        {
            cout << "List is empty!\n";
            return;
        }

        Node *temp = head;

        while (temp != NULL && temp->data != val)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Value not found!\n";
            return;
        }

        if (temp == head)
        {
            delete_front();
            return;
        }

        if (temp == tail)
        {
            delete_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
