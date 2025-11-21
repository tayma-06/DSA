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

class SinglyLinkedList
{
    Node *head;
    Node *tail;

public:
    // Constructor
    SinglyLinkedList()
    {
        head = tail = NULL;
    }

    // Is empty?
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
        tail->next = newNode;
        tail = newNode;
    }

    // Insert after
    void insertAfter(int refVal, int newVal)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        if (tail->data == refVal)
        {
            insertAtTail(newVal);
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
        Node *insertNode = new Node(newVal);
        insertNode->next = temp->next;
        temp->next = insertNode;
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
            cout << "Value to update does not exist" << endl;
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
        if (head->data == val)
        {
            Node *nextNode = head->next;
            delete head;
            head = nextNode;
            if (head == NULL)
            {
                tail = NULL;
            }
            return;
        }
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL && curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }
        if (curr == tail)
        {
            tail = prev;
            tail->next = NULL;
        }
        else
        {
            prev->next = curr->next;
        }
        delete curr;
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
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    SinglyLinkedList sll;
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