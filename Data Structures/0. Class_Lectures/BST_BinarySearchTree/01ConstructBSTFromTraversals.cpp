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

Node *buildBSTFromPreorder(vector<int> &pre, int &idx, int minVal, int maxVal)
{
    if (idx >= pre.size())
    {
        return NULL;
    }
    int val = pre[idx];
    if (val < minVal || val > maxVal)
    {
        return NULL;
    }
    Node *root = new Node(val);
    idx++;
    root->left = buildBSTFromPreorder(pre, idx, minVal, val);
    root->right = buildBSTFromPreorder(pre, idx, val, maxVal);
    return root;
}

Node *buildBSTFromPostorder(vector<int> &post, int &idx, int minVal, int maxVal)
{
    if (idx < 0)
    {
        return NULL;
    }
    int val = post[idx];
    if (val < minVal || val > maxVal)
    {
        return NULL;
    }
    Node *root = new Node(val);
    idx--;
    root->right = buildBSTFromPostorder(post, idx, val, maxVal);
    root->left = buildBSTFromPostorder(post, idx, minVal, val);
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int choice;
    cout << "Choose traversal type to construct BST: " << endl;
    cout << "1. Preorder" << endl;
    cout << "2. Postorder" << endl;
    ;
    cout << "Enter choice: ";
    cin >> choice;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the values: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = NULL;

    if (choice == 1)
    {
        int idx = 0;
        root = buildBSTFromPreorder(arr, idx, INT_MIN, INT_MAX);
    }
    else if (choice == 2)
    {
        int idx = n - 1;
        root = buildBSTFromPostorder(arr, idx, INT_MIN, INT_MAX);
    }
    else
    {
        cout << "Invalid choice! ";
        return 0;
    }

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}