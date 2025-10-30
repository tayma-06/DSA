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

    bool isCycle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    Node *detectCycle()
    {
        Node *slow = head;
        Node *fast = head;
        bool isCycle = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                isCycle = true;
        }
        if (!isCycle)
            return NULL;
        slow = head;
        while (fast == slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    void removeCycle()
    {
        Node *slow = head;
        Node *fast = head;
        bool isCycle = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                isCycle = true;
        }
        if (!isCycle)
        {
            cout << "Not a Cycle" << endl;
        }
        slow = head;
        Node *prev = NULL;
        while (fast == slow)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
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
    ll.pushFront(4);
    ll.pushFront(3);
    ll.pushFront(2);
    ll.pushFront(1);
    ll.pushFront(5);

    ll.printList();

    cout << "Existence of Cycle: " << (ll.isCycle() ? "Yes" : "No") << endl;
    cout << "Cycle starts: " << ll.detectCycle()->data << endl;
    ll.removeCycle();
    cout << "After Removing: " << endl;
    ll.printList();
}