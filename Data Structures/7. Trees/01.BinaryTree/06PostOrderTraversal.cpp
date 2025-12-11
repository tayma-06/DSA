#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void postOrder(Node *node, vector<int> &res)
{
    if (node == NULL)
    {
        return;
    }
    postOrder(node->left, res);
    postOrder(node->right, res);
    res.push_back(node->data);
}

int main()
{
    // Constructed binary tree is
    //          1
    //        /   \
    //      2      3
    //    /  \
    //  4     5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res;
    postOrder(root, res);
    for (int val : res)
    {
        cout << val << " ";
    }
    cout << endl;
}