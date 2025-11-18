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

    bool isEmpty()
    {
        return head == NULL;
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

        while (curr != NULL && curr->data != key)
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
        if (isEmpty())
        {
            cout << "Underflow\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
            tail = NULL;
    }

    void deleteAtEnd()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void deleteInMiddle(int position)
    {
        if (position < 1 || isEmpty())
        {
            cout << "Invalid position\n";
            return;
        }
        if (position == 1)
        {
            deleteAtStart();
            return;
        }

        Node *curr = head;
        Node *prev = NULL;

        for (int i = 1; i < position && curr != NULL; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Position out of range\n";
            return;
        }

        prev->next = curr->next;

        if (curr == tail)
            tail = prev;

        delete curr;
    }

    void deleteAfter(int key)
    {
        if (isEmpty())
            return;

        Node *temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL)
        {
            cout << "No node exists after given key!\n";
            return;
        }

        Node *delNode = temp->next;
        temp->next = delNode->next;

        if (delNode == tail)
            tail = temp;

        delete delNode;
    }

    void deleteBefore(int key)
    {
        if (isEmpty() || head->data == key)
        {
            cout << "No node exists before given key!\n";
            return;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *beforePrev = NULL;

        while (curr != NULL && curr->data != key)
        {
            beforePrev = prev;
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Key not found!\n";
            return;
        }

        if (prev == head)
        {
            deleteAtStart();
            return;
        }

        beforePrev->next = curr;
        delete prev;
    }

    bool search(int target)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
