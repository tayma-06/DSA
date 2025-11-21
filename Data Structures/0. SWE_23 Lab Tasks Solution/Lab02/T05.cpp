#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *prev;
    Node(string val)
    {
        data = val;
        next = prev = NULL;
    }
};

class CircularDoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    // Constructor
    CircularDoublyLinkedList()
    {
        head = tail = NULL;
    }

    // Empty
    bool isEmpty()
    {
        return head == NULL;
    }

    // Insert At Head
    void insertAtHead(string val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    // Insert At Tail
    void insertAtTail(string val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }

    // Delete
    void deleteVal(string val)
    {
        if (isEmpty())
        {
            cout << "Empty" << endl;
            return;
        }
        if (head == tail && head->data == val)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
            return;
        }
        if (tail->data == val)
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
            return;
        }
        Node *temp = head->next;
        while (temp != head)
        {
            if (temp->data == val)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Not found" << endl;
    }
    // Search
    Node *search(string key)
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
    CircularDoublyLinkedList songs;
    int choices;
    string name;
    cout << "1. Insert At Tail" << endl;
    cout << "2. Insert At Head" << endl;
    cout << "3. Delete a Song" << endl;
    cout << "4. Search Song" << endl;
    cout << "5. Display Playlist" << endl;
    cout << "Enter choice: ";
    cin >> choices;
    switch (choices)
    {
    case 1:
        cout << "Enter song name: ";
        cin >> name;
        songs.insertAtTail(name);
        break;
    case 2:
        cout << "Enter song name: ";
        cin >> name;
        songs.insertAtHead(name);
        break;
    case 3:
        cout << "Enter song name to delete: ";
        cin >> name;
        songs.deleteVal(name);
        break;
    case 4:
        cout << "Enter song name to search: ";
        cin >> name;
        if (songs.search(name))
            cout << "Found" << endl;
        else
            cout << "Not Found" << endl;
        break;
    case 5:
        songs.display();
        break;
    default:
        cout << "Invalid choice" << endl;
    }
    return 0;
}