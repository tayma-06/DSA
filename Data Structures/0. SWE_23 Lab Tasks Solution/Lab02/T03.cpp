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

class CircularLinkedList
{
    Node *head;
    Node *tail;

public:
    // Constructor
    CircularLinkedList()
    {
        head = tail = NULL;
    }

    // Empty
    bool isEmpty()
    {
        return head == NULL;
    }

    // Insert At Head
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    // Insert At Tail
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void insertAfter(int refVal, int newNode)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        bool found = false;
        do
        {
            if (temp->data == refVal)
            {
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);
        if (!found)
        {
            cout << "ref value does not exist" << endl;
            return;
        }
        if (temp == tail)
        {
            insertAtTail(newNode);
            return;
        }
        Node *insertVal = new Node(newNode);
        insertVal->next = temp->next;
        temp->next = insertVal;
    }

    // Update
    void update(int oldVal, int newVal)
    {
        if (isEmpty())
        {
            cout << "Does not exist" << endl;
            return;
        }
        Node *temp = head;
        bool found = false;
        do
        {
            if (temp->data == oldVal)
            {
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);
        if (!found)
        {
            cout << "Does not exist" << endl;
            return;
        }
        temp->data = newVal;
    }

    // Delete
    void deleteVal(int val)
    {
        if (isEmpty())
        {
            cout << "Empty" << endl;
            return;
        }
        if (head->data == val)
        {
            if (head == tail)
            {
                delete head;
                head = tail = NULL;
                return;
            }
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        do
        {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != val);
        if (temp == head)
        {
            cout << "Not found" << endl;
            return;
        }
        if (temp == tail)
        {
            tail = prev;
            tail->next = head;
            delete temp;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Search
    Node *search(int key)
    {
        if (isEmpty())
            return NULL;

        Node *result = head;
        do
        {
            if (result->data == key)
                return result;
            result = result->next;
        } while (result != head);

        return NULL;
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
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "HEAD" << endl;
    }
};
int main()
{
    CircularLinkedList sll;
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