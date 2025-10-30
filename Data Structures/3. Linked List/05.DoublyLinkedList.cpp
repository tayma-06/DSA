#include <iostream>
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

    void pushFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "Invalid Operation List is Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }

    void popBack()
    {
        if (head == NULL)
        {
            cout << "Invalid Operation List is Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            head = tail = NULL;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }

    void printList()
    {
        Node *temp = head;
        cout << "The data in List: ";
        while (temp != NULL)
        {
            cout << temp->data << " "; // cout << (*temp).data;
            temp = temp->next;         // temp = (*temp).next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyList dll;

    dll.pushFront(1);
    dll.pushFront(0);

    dll.printList();

    dll.pushBack(2);
    dll.pushBack(3);

    dll.printList();

    dll.popFront();

    dll.printList();

    dll.popBack();

    dll.printList();
}