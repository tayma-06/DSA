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

class SinglyList
{
    Node *head;
    Node *tail;

public:
    SinglyList()
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
        tail = newNode;
    }

    void push_after(int val, int key)
    {
        if (isEmpty())
        {
            cout << "No element in the List" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "No key found" << endl;
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail)
        {
            tail = newNode;
        }
    }

    void push_before(int val, int key)
    {
        if (isEmpty())
        {
            cout << "The List is empty" << endl;
            return;
        }
        if (head->data == key)
        {
            push_front(val);
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
            cout << "Key not found!" << endl;
            return;
        }
        Node *newNode = new Node(val);
        prev->next = newNode;
        newNode->next = curr;
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "No element in the List" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back()
    {
        if (isEmpty())
        {
            cout << "No elements in the List" << endl;
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

    void pop_after(int key)
    {
        if (isEmpty())
        {
            cout << "The list is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "No node exists after given key!" << endl;
            return;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        if (delNode == tail)
        {
            pop_back();
            return;
        }
        delete delNode;
    }

    void pop_before(int key)
    {
        if (isEmpty() || head->data == key)
        {
            cout << "Not Possible" << endl;
            return;
        }
        Node *prev_prev = NULL;
        Node *prev = head;
        Node *curr = head->next;
        while (curr != NULL && curr->data != key)
        {
            prev_prev = prev;
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "Key not found" << endl;
            return;
        }
        prev_prev->next = curr;
        delete prev;
    }

    bool search(int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "The List is Empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};