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

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "Invalid Operation" << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }

    void deleteAtTail()
    {
        if (tail == NULL)
        {
            cout << "Invalid Operation. List is Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }
        cout << "Data in the List : " << endl;
        cout << head->data << " ";
        Node *temp = head->next;
        while (temp != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    CircularList cll;

    cll.insertAtHead(5);
    cll.insertAtHead(4);

    cll.printList();

    cll.insertAtTail(2);
    cll.insertAtTail(1);

    cll.printList();

    cll.deleteAtHead();
    cll.printList();

    cll.deleteAtTail();
    cll.printList();

    return 0;
}