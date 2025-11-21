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
    CircularLinkedList()
    {
        head = tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    // Insert at front
    void insert_front(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }

    // Insert at back
    void insert_back(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    // Insert after a node with data == key
    void insert_after_node(int key, int val)
    {
        if (isEmpty())
        {
            cout << "List Empty" << endl;
            return;
        }

        Node *curr = head;

        do
        {
            if (curr->data == key)
            {
                Node *newNode = new Node(val);

                newNode->next = curr->next;
                curr->next = newNode;

                if (curr == tail)
                    tail = newNode;

                return;
            }
            curr = curr->next;
        } while (curr != head);

        cout << "Key not found!" << endl;
    }

    // Delete at front
    void remove_head()
    {
        if (isEmpty())
        {
            cout << "Invalid as the list is empty." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    // Delete at back
    void remove_end()
    {
        if (isEmpty())
        {
            cout << "Invalid since list is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != tail)
        {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    }

    // Remove element
    void remove_element(int key)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == key)
        {
            remove_head();
            return;
        }
        if (tail->data == key)
        {
            remove_end();
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        do
        {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->next->data != key);
        if (temp == head)
        {
            cout << "Element does not exist" << endl;
            return;
        }
        prev->next = temp->next;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "List Empty" << endl;
            return;
        }

        Node *curr = head;
        do
        {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);

        cout << "NULL" << endl;
    }
};

int main()
{
    CircularLinkedList cll;
    int choices;
    cout << "Press 1 to insert at front" << endl;
    cout << "Press 2 to insert at end" << endl;
    cout << "Press 3 to insert after a node" << endl;
    cout << "Press 4 to update a node" << endl;
    cout << "Press 5 to delete the front" << endl;
    cout << "Press 6 to delete the end" << endl;
    cout << "Press 7 to remove a node" << endl;
    cout << "Press 8 to exit" << endl;
}
