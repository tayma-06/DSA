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
        head = tail = NULL;
    }

    void pushFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head; // (*newNode).next = head;
            head = newNode;
        }
    }

    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail = curr;
        head = prev;
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
    List ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(4);
    ll.pushFront(5);

    cout << "Originally: " << endl;
    ll.printList();

    ll.reverse();

    cout << "After Reverse: " << endl;
    ll.printList();

    return 0;
}