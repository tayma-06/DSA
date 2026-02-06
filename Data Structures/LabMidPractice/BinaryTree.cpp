#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
Node *search(Node *root, int value)
{
    if (!root)
        return nullptr;
    if (root->data == value)
        return root;
    Node *leftSearch = search(root->left, value);
    if (leftSearch)
        return leftSearch;
    return search(root->right, value);
}
void insertNode(Node *root, int parentVal, int childVal, char dir)
{
    Node *parent = search(root, parentVal);
    if (!parent)
        return;

    if (dir == 'L')
        parent->left = new Node(childVal);
    else
        parent->right = new Node(childVal);
}
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
}
int height(Node *root)
{
    if (!root)
        return -1;
    return 1 + max(height(root->left), height(root->right));
}

int sumTree(Node *root)
{
    if (!root)
        return 0;
    return root->data + sumTree(root->left) + sumTree(root->right);
}

int countLeaves(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void levelMax(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        int mx = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            Node *cur = q.front();
            q.pop();
            mx = max(mx, cur->data);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        cout << mx << " ";
    }
}
int main()
{
    int N;
    cin >> N;
    int rootVal;
    cin >> rootVal;
    Node *root = new Node(rootVal);
    for (int i = 0; i < N - 1; i++)
    {
        int p, c;
        char d;
        cin >> p >> c >> d;
        insertNode(root, p, c, d);
    }
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;
    cout << "Height: " << height(root) << endl;
    cout << "Level Max: ";
    levelMax(root);
    cout << endl;
    cout << "Sum: " << sumTree(root) << endl;
    cout << "Leaf Nodes: " << countLeaves(root) << endl;
    return 0;
}
