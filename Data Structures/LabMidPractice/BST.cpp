#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right, *parent;
    int height;
    Node(int k)
    {
        key = k;
        left = right = parent = nullptr;
        height = 0;
    }
};

class BST
{
private:
    Node *root;
    void update_height(Node *node)
    {
        while (node)
        {
            int lh = (node->left) ? node->left->height : -1;
            int rh = (node->right) ? node->right->height : -1;
            int newHeight = max(lh, rh) + 1;
            if (node->height == newHeight)
                break;
            node->height = newHeight;
            node = node->parent;
        }
    }
    Node *searchNode(int key)
    {
        Node *cur = root;
        while (cur)
        {
            if (key == cur->key)
                return cur;
            if (key < cur->key)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return nullptr;
    }
    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
    Node *subtreeMin(Node *node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }
    Node *subtreeMax(Node *node)
    {
        while (node && node->right)
            node = node->right;
        return node;
    }

public:
    BST() { root = nullptr; }
    void insert(int key)
    {
        if (!root)
        {
            root = new Node(key);
            print_tree();
            return;
        }
        Node *cur = root;
        Node *parent = nullptr;
        while (cur)
        {
            parent = cur;
            if (key < cur->key)
                cur = cur->left;
            else
                cur = cur->right;
        }
        Node *newNode = new Node(key);
        newNode->parent = parent;
        if (key < parent->key)
            parent->left = newNode;
        else
            parent->right = newNode;
        update_height(parent);
        print_tree();
    }
    void print_tree()
    {
        inorder(root);
        cout << endl;
    }
    void search(int key)
    {
        Node *node = searchNode(key);
        if (!node)
        {
            cout << "Not Found" << endl;
            return;
        }
        cout << "Present" << endl;
        cout << "P(" << (node->parent ? to_string(node->parent->key) : "NULL") << "), ";
        cout << "L(" << (node->left ? to_string(node->left->key) : "NULL") << "), ";
        cout << "R(" << (node->right ? to_string(node->right->key) : "NULL") << ")" << endl;
    }
    void get_height(int key)
    {
        Node *node = searchNode(key);
        if (!node)
        {
            cout << "Not Found" << endl;
            return;
        }
        cout << node->height << endl;
    }
    void before_after(int key)
    {
        Node *node = searchNode(key);
        if (!node)
        {
            cout << "Not Found" << endl;
            return;
        }
        Node *pred = nullptr;
        Node *succ = nullptr;

        if (node->left)
            pred = subtreeMax(node->left);
        else
        {
            Node *cur = node;
            while (cur->parent && cur == cur->parent->left)
                cur = cur->parent;
            pred = cur->parent;
        }
        if (node->right)
            succ = subtreeMin(node->right);
        else
        {
            Node *cur = node;
            while (cur->parent && cur == cur->parent->right)
                cur = cur->parent;
            succ = cur->parent;
        }
        cout << (pred ? to_string(pred->key) : "null") << " ";
        cout << (succ ? to_string(succ->key) : "null") << endl;
    }
    void max_min(int key)
    {
        Node *node = searchNode(key);
        if (!node)
        {
            cout << "Not Found" << endl;
            return;
        }
        Node *mn = subtreeMin(node);
        Node *mx = subtreeMax(node);

        cout << mn->key << " " << mx->key << endl;
    }
    void delete_value(int key)
    {
        Node *node = searchNode(key);
        if (!node)
        {
            cout << "Value not found" << endl;
            print_tree();
            return;
        }

        Node *parent = node->parent;
        if (!node->left || !node->right)
        {
            Node *child = node->left ? node->left : node->right;
            if (!parent)
                root = child;
            else if (parent->left == node)
                parent->left = child;
            else
                parent->right = child;
            if (child)
                child->parent = parent;
            delete node;
            update_height(parent);
        }
        else
        {
            Node *succ = subtreeMin(node->right);
            node->key = succ->key;
            delete_value(succ->key);
            return;
        }

        print_tree();
    }
    Node *find_lca_node(int a, int b)
    {
        Node *n1 = searchNode(a);
        Node *n2 = searchNode(b);
        if (!n1 || !n2)
            return nullptr;
        while (n1->height > n2->height)
            n1 = n1->parent;
        while (n2->height > n1->height)
            n2 = n2->parent;
        while (n1 != n2)
        {
            n1 = n1->parent;
            n2 = n2->parent;
        }
        return n1;
    }
    void find_lca(int a, int b)
    {
        Node *lca = find_lca_node(a, b);
        if (!lca)
        {
            cout << "Invalid Input" << endl;
            return;
        }
        cout << lca->key << endl;
    }
    void describe_lca(int a, int b)
    {
        Node *lca = find_lca_node(a, b);
        if (!lca)
        {
            cout << "Invalid Input" << endl;
            return;
        }
        auto distance = [&](int x)
        {
            Node *n = searchNode(x);
            int d = 0;
            while (n != lca)
            {
                n = n->parent;
                d++;
            }
            return d;
        };
        cout << "LCA: " << lca->key << endl;
        cout << "Path to " << a << ": " << distance(a) << endl;
        cout << "Path to " << b << ": " << distance(b) << endl;
    }
};

int main()
{
    BST tree;
    int choice;

    while (cin >> choice)
    {
        if (choice == 0)
            break;

        if (choice == 1)
        {
            int x;
            cin >> x;
            tree.insert(x);
        }
        else if (choice == 2)
        {
            int x;
            cin >> x;
            tree.delete_value(x);
        }
        else if (choice == 3)
        {
            int x;
            cin >> x;
            tree.search(x);
        }
        else if (choice == 4)
        {
            int x;
            cin >> x;
            tree.get_height(x);
        }
        else if (choice == 5)
        {
            int x;
            cin >> x;
            tree.before_after(x);
        }
        else if (choice == 6)
        {
            int x;
            cin >> x;
            tree.max_min(x);
        }
        else if (choice == 7)
        {
            int x, y;
            cin >> x >> y;
            tree.find_lca(x, y);
        }
        else if (choice == 8)
        {
            int x, y;
            cin >> x >> y;
            tree.describe_lca(x, y);
        }
    }
    return 0;
}
