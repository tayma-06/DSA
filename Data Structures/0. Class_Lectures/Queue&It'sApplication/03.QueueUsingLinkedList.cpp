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
class myListQueue
{
    Node *head;
    Node *tail;
    public:
    myListQueue()
    {
        head = tail = NULL;
    }
    void enqueue(int val)
    {
        if(head == NULL)
        {
            
        }
    }
};
