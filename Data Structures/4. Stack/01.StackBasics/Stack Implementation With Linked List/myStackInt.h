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

class myStack
{
    Node *top;

public:
    myStack()
    {
        top = NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        if (top == NULL)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack empty" << endl;
            return;
        }
        else if (top->next == NULL)
        {
            top == NULL;
            delete top;
            return;
        }
        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
        return top->data;
    }

    int size()
    {
        Node *temp = top;
        int size = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }

    bool isEmpty()
    {
        return top == NULL ? true : false;
    }
};