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

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    void pushFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = NULL;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void popFront()
    {
        if (empty())
        {
            cout << "Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = temp->next;
        delete temp;
    }

    void popBack()
    {
        if (empty())
        {
            cout << "Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insertAfter(int val, int key)
    {
        if(empty())
        {
            return;
        }
        Node *temp = head;
        while(temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if(temp == NULL)
        {
            cout << "Invalid Key" << endl;
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if(temp == tail)
        {
            tail = newNode;
        }
    }

    void deleteAfter(int key)
    {
        if(empty())
        {
            return;
        }
        Node *temp = head;
        while(temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if(temp == NULL || temp->next == NULL)
        {
            cout << "Invalid Key" << endl;
            return;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        if(delNode == tail)
        {
            tail = temp;
        }
        delete delNode;
    }

    bool search(int key)
    {
        if(empty())
        {
            cout << "Empty" << endl;
        }
        Node *temp = head;
        while(temp != NULL && temp->data == key)
        {
            temp = temp->next;
        }
        if(temp == NULL)
        {
            return false;
        }
        return true;
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
        if(choice == 0) 
        {
            break;
        }
        switch (choice)
        {
        case 1: // pushFront
            cin >> value;
            ll.pushFront(value);
            ll.print();
            break;
        case 2: // pushBack
            cin >> value;
            ll.pushBack(value);
            ll.print();
            break;
        case 3: // popFront
            ll.popFront();
            ll.print();
            break;
        case 4: // popBack
            ll.popBack();
            ll.print();
            break;
        case 5: // insertAfter
            cin >> value >> value2;
            ll.insertAfter(value, value2);
            ll.print();
            break;
        case 6: // deleteAfter
            cin >> value2;
            ll.deleteAfter(value2);
            ll.print();
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
}