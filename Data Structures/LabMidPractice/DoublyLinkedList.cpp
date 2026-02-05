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

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
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
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
            return;
        }
        if (head == tail)
        {
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
            return;
        }
        if (head == tail)
        {
            head = tail = NULL;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
    bool empty()
    {
        return head == NULL;
    }
    void print()
    {
        Node *temp = head;
        cout << "The data i List: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List ll;
    cout << "Enter your choice: ";
    while (true)
    {
        int choice, value, value2;
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1: // pushFront
            cin >> value;
            ll.push_front(value);
            ll.print();
            break;
        case 2: // pushBack
            cin >> value;
            ll.push_back(value);
            ll.print();
            break;
        case 3: // popFront
            ll.pop_front();
            ll.print();
            break;
        case 4: // popBack
            ll.pop_back();
            ll.print();
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
}