
// THIS MAY NOT BE THE MOST OPTIMAL SOLUTION BUT I PUT A LOT OF EFFORT IN IT
// SO JUST BEAR WITH IT

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    int height;
    Node(int val)
    {
        data = val;
        left = right = parent = NULL;
        height = 0;
    }
};

class BST
{
    Node *root;

public:
    // Task 01
    BST()
    {
        root = NULL;
    }
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        Node *curr = root;
        Node *prev = NULL;
        while (curr != NULL)
        {
            prev = curr;
            if (value < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (value < prev->data)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
        newNode->parent = prev;
        Node *temp = newNode;
        while (temp->parent != NULL)
        {
            temp = temp->parent;
            if (temp->left != NULL && temp->right != NULL)
                temp->height = max(temp->left->height, temp->right->height) + 1;
            else if (temp->left != NULL)
            {
                temp->height = temp->left->height + 1;
            }
            else
            {
                temp->height = temp->right->height + 1;
            }
        }
    }

    void inOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void search(int key)
    {
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->data == key)
            {
                cout << "Found" << endl;
                return;
            }
            else if (key < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        cout << "Not Found" << endl;
        return;
    }

    int get_height(int value)
    {
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->data == value)
            {
                return curr->height;
            }
            else if (value < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        return -1;
    }
    void print_tree()
    {
        inOrder(root);
        cout << endl;
    }
    void before_after(int key)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                break;
            }
            else if (key < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
            // {
            //     if (temp->parent == NULL && temp->right == NULL)
            //     {
            //         cout << "Invalid";
            //         return;
            //     }
            //     else
            //     {
            //         cout << temp->parent->data << " ";
            //         cout << temp->right->data << endl;
            //         return;
            //     }
            // }
            // else if (key < temp->data)
            // {
            //     temp = temp->left;
            // }
            // else
            // {
            //     temp = temp->right;
            // }
        }
        if (temp == NULL)
        {
            cout << "Invalid" << endl;
            return;
        }
        Node *before = NULL;
        if (temp->left != NULL)
        {
            before = temp->left;
            while (before->right != NULL)
                before = before->right;
        }
        else
        {
            Node *curr = temp;
            Node *par = temp->parent;
            while (par != NULL && curr == par->left)
            {
                curr = par;
                par = par->parent;
            }
            before = par;
        }
        Node *after = NULL;
        if (temp->right != NULL)
        {
            after = temp->right;
            while (after->left != NULL)
            {
                after = after->left;
            }
        }
        else
        {
            Node *curr = temp;
            Node *par = temp->parent;
            while (par != NULL && curr == par->right)
            {
                curr = par;
                par = par->parent;
            }
            after = par;
        }
        if (before)
            cout << before->data << " ";
        else
            cout << "NULL ";
        if (after)
            cout << after->data << endl;
        else
            cout << "NULL" << endl;
    }
    void max_min(int key)
    {
        Node *curr = root;
        int min = INT_MAX, max = INT_MIN;
        while (curr != NULL)
        {
            if (curr->data == key)
            {
                break;
            }
            else if (key < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (curr == NULL)
        {
            cout << "Invalid" << endl;
            return;
        }
        Node *temp = curr;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        cout << temp->data << " ";
        temp = curr;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        cout << temp->data << endl;
    }
    // Task 02
    void deleteNode(int val)
    {
        root = deleteNodeRecursive(root, val);
        if (root)
            root->parent = NULL;
    }
    Node *findLargest(Node *node)
    {
        if (node == NULL)
            return node;
        while (node->right != NULL)
        {
            node = node->right;
        }
        return node;
    }
    Node *deleteNodeRecursive(Node *node, int val)
    {
        if (node == NULL)
            return node;
        if (val < node->data)
        {
            node->left = deleteNodeRecursive(node->left, val);
            if (node->left)
                node->left->parent = node;
        }
        else if (val > node->data)
        {
            node->right = deleteNodeRecursive(node->right, val);
            if (node->right)
                node->right->parent = node;
        }
        else
        {
            if (node->left == NULL)
            {
                Node *temp = node->right;
                if (temp)
                    temp->parent = node->parent;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node *temp = node->left;
                if (temp)
                    temp->parent = node->parent;
                delete node;
                return temp;
            }
            else
            {
                Node *predecessor = node->left;
                while (predecessor->right != NULL)
                {
                    predecessor = predecessor->right;
                }
                node->data = predecessor->data;
                node->left = deleteNodeRecursive(node->left, predecessor->data);
                if (node->left)
                    node->left->parent = node;
            }
        }
        updateSingleNodeHeight(node);
        return node;
    }
    void updateSingleNodeHeight(Node *node)
    {
        if (node == NULL)
            return;
        int leftHeight = (node->left) ? node->left->height : -1;
        int rightHeight = (node->right) ? node->right->height : -1;
        node->height = max(leftHeight, rightHeight) + 1;
    }
    // void updateHeight(Node *node)
    // {
    //     while (node != NULL)
    //     {
    //         updateSingleNodeHeight(node);
    //         node = node->parent;
    //     }
    // }
    // Task 03
    Node *find(Node *node, int val)
    {
        if (node == NULL || node->data == val)
        {
            return node;
        }
        else if (val < node->data)
        {
            return find(node->left, val);
        }
        else
        {
            return find(node->right, val);
        }
    }
    Node *find_lca_by_height(Node *n1, Node *n2)
    {
        if (n1 == NULL || n2 == NULL)
            return NULL;
        if (n1 == n2)
            return n1;
        if (n1->height > n2->height)
        {
            if (n1->parent == NULL)
            {
                Node *temp = n2;
                while (temp != NULL)
                {
                    if (temp == n1)
                        return n1;
                    temp = temp->parent;
                }
                return find_lca_by_height(n1, n2->parent);
            }
            return find_lca_by_height(n1->parent, n2);
        }
        else if (n2->height > n1->height)
        {
            if (n2->parent == NULL)
            {
                Node *temp = n1;
                while (temp != NULL)
                {
                    if (temp == n2)
                        return n2;
                    temp = temp->parent;
                }
                return find_lca_by_height(n1->parent, n2);
            }
            return find_lca_by_height(n1, n2->parent);
        }
        else
        {
            if (n1->parent == NULL || n2->parent == NULL)
            {
                return (n1->parent == NULL) ? n1 : n2;
            }
            return find_lca_by_height(n1->parent, n2->parent);
        }
    }
    bool isAncestor(Node *a, Node *b)
    {
        while (b != NULL)
        {
            if (b == a)
                return true;
            b = b->parent;
        }
        return false;
    }
    Node *find_lca(int val1, int val2)
    {
        Node *n1 = find(root, val1);
        Node *n2 = find(root, val2);
        if (!n1 || !n2)
            return NULL;
        if (isAncestor(n1, n2))
            return n1;
        if (isAncestor(n2, n1))
            return n2;
        return find_lca_by_height(n1, n2);
    }

    void describe_lca(int val1, int val2)
    {
        Node *lca = find_lca(val1, val2);
        if (lca == NULL)
        {
            cout << "Invalid input" << endl;
            return;
        }
        Node *node1 = find(root, val1);
        Node *node2 = find(root, val2);
        cout << lca->data << endl;
        if (node1 && node2)
        {
            cout << "1. " << node1->data << " 2. " << node2->data << endl;
        }
    }
    Node *getRoot()
    {
        return root;
    }
};

int main()
{
    BST tree;
    int choice, val, val2;
    while (true)
    {
        cin >> choice;
        if (choice == 9)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            cin >> val;
            tree.insert(val);
            tree.print_tree();
            break;
        case 2:
            cin >> val;
            tree.deleteNode(val);
            tree.print_tree();
            break;
        case 3:
            cin >> val;
            tree.search(val);
            break;
        case 4:
            cin >> val;
            cout << tree.get_height(val) << endl;
            break;
        case 5:
            cin >> val;
            tree.before_after(val);
            break;
        case 6:
            cin >> val;
            tree.max_min(val);
            break;
        case 7:
        {
            cin >> val >> val2;
            Node *lca_node = tree.find_lca(val, val2);
            if (lca_node != NULL)
                cout << lca_node->data << endl;
            else
                cout << "Invalid input" << endl;
            break;
        }
        case 8:
        {
            cin >> val >> val2;
            Node *lca = tree.find_lca(val, val2);
            if (lca != NULL)
            {
                cout << lca->data << endl;
                Node *node1 = tree.find(tree.getRoot(), val);
                Node *node2 = tree.find(tree.getRoot(), val2);
                cout << "1. " << node1->data << " 2. " << node2->data << endl;
            }
            else
            {
                cout << "Invalid input" << endl;
            }
            break;
        }
        }
    }
    return 0;
}