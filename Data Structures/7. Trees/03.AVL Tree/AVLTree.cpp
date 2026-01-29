#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};
class AVLTree
{
private:
    Node *root;
    int height(Node *node)
    {
        return node ? node->height : 0;
    }
    int getBalance(Node *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    Node *insert(Node *node, int key)
    {
        if (!node)
            return new Node(key);
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);
        if (balance > 1 && key > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    bool search(Node *node, int key)
    {
        if (!node)
            return false;
        if (node->data == key)
            return true;
        if (key < node->data)
            return search(node->left, key);
        return search(node->right, key);
    }
    void preOrder(Node *node)
    {
        if(node == NULL)
        {
            return;
        }
        preOrder(node->left);
        cout << node->data << " ";
        preOrder(node->right);
    }

public:
    AVLTree()
    {
        root = NULL;
    }
    void insert(int key)
    {
        root = insert(root, key);
    }
    bool search(int key)
    {
        return search(root, key);
    }
    void printPreOrder()
    {
        preOrder(root);
        cout << endl;
    }
};
int main()
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    cout << "Level Order: ";
    tree.printPreOrder();
    cout << tree.search(45) << endl;
    cout << tree.search(25) << endl;
    return 0;
}
