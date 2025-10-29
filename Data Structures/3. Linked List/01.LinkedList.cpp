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
        head = NULL;
        tail = NULL;
    }

    // Basic functions of a linked list:
    // pushFront - insert at the beginning
    // pushBack - insert at the end
    // popFront - remove from the beginning
    // popBack - remove from the end

    // pushFront
    void pushFront(int val)
    {
        Node* newNode = new Node(val); // dynamic
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head; // (*newNode).next = head;
            head = newNode;
        }
    }

    // pushBack
    void pushBack(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        } 
        else
        {
            tail->next = newNode; // (*tail).next = newNode;
            tail = newNode;
        }

    }
    
    // popFront
    void popFront()
    {
        if(head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        else if(head->next == NULL) // only one node
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node* temp = head;
            head = head->next; // head = (*head).next;
            delete temp;
        }
    }

    // popBack
    void popBack()
    {
        if(head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        else if(head->next == NULL) // only one node
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node* temp = head;
            while(temp->next != tail) // while((*temp).next != tail)
            {
                temp = temp->next; // temp = (*temp).next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL; // (*tail).next = NULL;
        }
    }

    // printList
    void printList()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " -> "; // cout << (*temp).data << " -> ";
            temp = temp->next; // temp = (*temp).next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);

    ll.printList();

    ll.pushBack(4);
    ll.pushBack(5);
    ll.pushBack(6);

    ll.printList();

    ll.popFront();

    ll.printList();

    ll.popBack();

    ll.printList();
}
