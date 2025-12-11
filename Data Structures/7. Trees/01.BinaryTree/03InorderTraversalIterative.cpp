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

vector<int> inOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        ans.push_back(curr->data);
        curr = curr->right;
    }
    return ans;
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

    vector<int> res = inOrder(root);
    for (int val : res)
    {
        cout << val << " ";
    }
    cout << endl;
}