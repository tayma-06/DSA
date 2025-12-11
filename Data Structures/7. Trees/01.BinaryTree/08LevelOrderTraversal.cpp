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

void levelOrderRecord(Node *root, int level, vector<vector<int>> &res)
{
    if (root == NULL)
        return;
    if (res.size() <= level)
        res.push_back({});
    res[level].push_back(root->data);
    levelOrderRecord(root->left, level + 1, res);
    levelOrderRecord(root->right, level + 1, res);
}

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> res;
    levelOrderRecord(root, 0, res);
    return res;
}

int main()
{
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14   2
    // / \  /  \  / \
    // 17 23 27 3  8  11

    Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    vector<vector<int>> res = levelOrder(root);

    for (vector<int> level : res)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}