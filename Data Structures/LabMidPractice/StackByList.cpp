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

class Stack
{
    Node *head;
    Node *tail;
    int size;

public:
    Stack()
    {
        head = tail = NULL;
        size = 0;
    }
    void push(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            head = tail = NULL;
            size--;
            return;
        }
        Node *temp = head;
        head = temp->next;
        size--;
        delete temp;
    }
    int sizeOf()
    {
        return size;
    }
    bool empty()
    {
        return head == NULL;
    }
    int peek()
    {
        return head->data;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    while (true)
    {
        int choice, val;
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1: // push(val)
            cin >> val;
            st.push(val);
            st.print();
            break;
        case 2: // pop(val)
            st.pop();
            st.print();
            break;
        case 3: // peek
            cout << st.peek() << endl;
            break;
        case 4: // size
            cout << st.sizeOf() << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
}