#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void insertAtStart(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void insertAfter(int val, int key)
    {
        if (isEmpty())
            return;
        Node *temp = head;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Key not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail)
            tail = newNode;
    }

    void insertBefore(int val, int key)
    {
        if (isEmpty())
            return;
        if (head->data == key)
        {
            insertAtStart(val);
            return;
        }
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL && curr->data == key)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "Key not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        prev->next = newNode;
        newNode->next = curr;
    }

    void deleteAtStart()
    {
    }

    void deleteAtEnd()
    {
    }

    void deleteInMiddle()
    {
    }

    void deleteAfter(int key)
    {
    }

    void deleteBefore(int key)
    {
    }

    void search(int target)
    {
    }

    bool isEmpty()
    {
        return head == NULL ? true : false;
    }

    void display()
    {
    }
};
