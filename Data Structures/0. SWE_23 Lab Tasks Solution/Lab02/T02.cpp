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

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    // Constructor
    DoublyLinkedList()
    {
        head = tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    // Insert at head
    void insertAtHead(int val)
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

    // Insert at tail
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // Insert After
    void insertAfter(int refVal, int newVal)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->data != refVal)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Reference value not found" << endl;
            return;
        }
        if (temp == tail)
        {
            insertAtTail(newVal);
            return;
        }
        Node *newNode = new Node(newVal);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Update
    void update(int oldVal, int newVal)
    {
        Node *temp = head;
        while (temp != NULL && temp->data != oldVal)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }
        temp->data = newVal;
    }

    // Delete
    void deleteVal(int val)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->data != val)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Not found" << endl;
            return;
        }
        if (head == tail && temp == head)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        if (temp == head)
        {
            head = head->next;
            head->prev = NULL;
            delete temp;
            return;
        }
        if (temp == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Search
    Node *search(int key)
    {
        Node *temp = head;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        return temp;
    }

    // Display
    void display()
    {
        if (isEmpty())
        {
            cout << "Empty List" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLinkedList sll;
    sll.insertAtHead(5);
    sll.insertAtTail(6);
    sll.insertAfter(5, 7);
    sll.insertAtHead(3);
    sll.insertAtHead(2);
    sll.insertAtHead(1);
    sll.display();
    cout << (sll.search(200) ? "Found" : "Not Found") << endl;
    cout << (sll.search(2) ? "Found" : "Not Found") << endl;
    sll.deleteVal(1);
    sll.display();
    sll.deleteVal(5);
    sll.display();
    sll.deleteVal(6);
    sll.display();
    return 0;
}