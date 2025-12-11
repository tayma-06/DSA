#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
    Node(int x)
    {
        data = x;
    }
};