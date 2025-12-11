#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class myDeque
{
    Node* front;
    Node* rear;
    public:
    myDeque()
    {
        front=rear=NULL;
    }
    void push_front(int x)
    {
        Node* newNode = new Node(x);
        if(front == NULL)
        {
            front = rear = newNode;
            return;
        }
        newNode->next = front;
        front = newNode;
        cout << "OK" << endl;
    }
    void pop_front()
    {
        if(front == NULL)
        {
            cout << "Empty queue" << endl;
            return;
        }
        Node*temp=front;
        front = front->next;
        temp->next = NULL;
        delete temp;
        cout << "OK" <<endl;
    }
    int getFront()
    {
        if(front == NULL)
        {
            cout << "Empty queue" << endl;
            return -1;
        }
        return front->data;
    }
    void push_back(int x)
    {
        Node* newNode = new Node(x);
        if(front == NULL)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear=newNode;
        cout << "OK" << endl;
    }
    void pop_back()
    {
        if(front==NULL)
        {
            cout<<"Queue is empty!" << endl;
            return;
        }
        Node *temp=front;
        while(temp->next != rear)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete rear;
        rear = temp;
        cout << rear->data <<endl;
        cout << "OK" << endl;
    }
    int getBack()
    {
        if(front==NULL)
        {
            cout << "No element" << endl;
            return -1;
        }
        return rear->data;
    }
    int size()
    {
        if(front == NULL)
        {
            cout << "Empty" << endl;
            return 0;
        }
        if(front == rear)
        {
            return 1;
        }
        Node*temp = front;
        int size=0;
        while(temp!=NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
};

int main()
{
    cout << "Task 01" << endl;
    myDeque dq;
    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(15);

    cout << dq.getFront() << endl;
    cout << dq.getBack() << endl;
    cout << dq.size() << endl;

    dq.pop_back();
    dq.pop_front();

    cout << dq.getFront() << endl;
    cout << dq.getBack() << endl;
    cout << dq.size() << endl;

    return 0;
}