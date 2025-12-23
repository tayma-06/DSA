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

Node *search(Node *root, int val)
{
    if (root == NULL or root->data == val)
    {
        return root;
    }
    if (val < root->data)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

Node *findSmallestNode(Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    return findSmallestNode(root->left);
}

Node *findLargestNode(Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    return findLargestNode(root->right);
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        if (root->left && root->right)
        {
            Node *temp = findLargestNode(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
        else
        {
            Node *temp = root;
            if (root->left == NULL)
            {
                root = root->right;
            }
            else if (root->right == NULL)
            {
                root = root->left;
            }
            delete temp;
        }
    }
    return root;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left) + 1, height(root->right) + 1);
}

int totalNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (totalNodes(root->left) + totalNodes(root->right) + 1);
}

int totalExternalNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return (totalExternalNodes(root->left) + totalExternalNodes(root->right));
}

int totalInternalNodes(Node *root)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    return (totalInternalNodes(root->left) + totalInternalNodes(root->right) + 1);
}

int main()
{
    Node *root = NULL;
    int n;

    cout << "Enter number of Nodes: ";
    cin >> n;

    cout << "Enter the values: " << endl;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cout << "Height of the Tree: " << height(root) << endl;
    cout << "Total nodes: " << totalNodes(root) << endl;
    cout << "Total external (leaf) nodes: " << totalExternalNodes(root) << endl;
    cout << "Total internal nodes: " << totalInternalNodes(root) << endl;

    int key;
    cout << "Enter a value to search in the tree: ";
    cin >> key;

    if (search(root, key))
        cout << "Found! :D\n";
    else
        cout << "Not Found! :(\n";

    int del;
    cout << "Enter value to delete: ";
    cin >> del;

    root = deleteNode(root, del);

    return 0;
}