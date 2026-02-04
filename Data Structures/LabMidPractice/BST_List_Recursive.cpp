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

class BST
{
    Node *root;

    Node *insert(Node *node, int val)
    {
        if (node == NULL)
        {
            return new Node(val);
        }

        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else
        {
            node->right = insert(node->right, val);
        }

        return node;
    }

    void inOrderPrint(Node *node)
    {
        if (node == NULL)
            return;

        inOrderPrint(node->left);
        cout << node->data << " ";
        inOrderPrint(node->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int val)
    {
        root = insert(root, val);
    }

    void inOrderPrint()
    {
        inOrderPrint(root);
    }
};

int main()
{
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.inOrderPrint();

    return 0;
}
