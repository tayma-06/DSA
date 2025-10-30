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

    Node *findMiddle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    int n;
    List ll;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        ll.pushFront(num);
    }
    cout << "Middle Element: " << ll.findMiddle()->data << endl;
    return 0;
}