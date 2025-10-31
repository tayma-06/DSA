// SingleList.h file
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
            newNode->next = head; // (*newNode).next = head;
            head = newNode;
        }
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "No Data. Invalid Operation" << endl;
            return;
        }
        else if (head == tail)
        {
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = head->next; // moving the head to next element
        temp->next = NULL; // disconnecting the first element from the list
        delete temp;       // deleting the first element
    }

    int getHead()
    {
        if (head == NULL)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return head->data;
    }

    int size()
    {
        int size = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }
};