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

    // pushBack
    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // popFront
    void popFront()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No Data. Invalid Operation" << endl;
            return;
        }
        else
        {
            head = head->next; // moving the head to next element
            temp->next = NULL; // disconnecting the first element from the list
            delete temp;       // deleting the first element
        }
    }

    // popBack
    void popBack()
    {
        if (head == NULL)
        {
            cout << "Our List is Empty. Invalid Operation" << endl;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // insert
    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos < 0)
            return;
        else if (pos == 0)
            pushFront(val);
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                if (temp == NULL)
                {
                    cout << "Invalid Operation and Position";
                    return;
                }
                temp = temp->next; // temp = (*temp).next;
            }
            newNode->next = temp->next; // (*newNode).next = (*temp).next;
            temp->next = newNode;       // (*temp).next = newNode;
        }
    }

    // search
    int search(int key)
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Found at index " << i << endl;
                return i;
            }
            temp = temp->next;
            i++;
        }
        cout << "Not Found" << endl;
        return -1;
    }

    // printList
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

    ll.printList();

    ll.pushBack(4);
    ll.pushBack(5);
    ll.pushBack(6);

    ll.printList();

    ll.popFront();

    ll.printList();

    ll.popBack();

    ll.printList();

    ll.insert(7, 2);
    ll.insert(9, 3);
    ll.insert(8, 0);

    ll.printList();

    ll.search(3);
    ll.search(5);

    return 0;
}