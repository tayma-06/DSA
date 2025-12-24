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

Node *searchIterative(Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
            root = root->right;
    }
    return NULL;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    Node *curr = root;
    Node *parent = NULL;
    while (curr != NULL)
    {
        parent = curr;
        if (val < curr->data)
        {
            curr = curr->left;
        }
        else if (val > curr->data)
        {
            curr = curr->right;
        }
        else
        {
            return root;
        }
    }
    if (val < parent->data)
    {
        parent->left = new Node(val);
    }
    else
    {
        parent->right = new Node(val);
    }
    return root;
}

Node *findMax(Node *root)
{
    while (root && root->right)
    {
        root = root->right;
    }
    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int key)
{
    Node *curr = root;
    Node *parent = NULL;
    while (curr && curr->data != key)
    {
        parent = curr;
        if (key < curr->data)
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
        return root;
    }
    if (curr->left && curr->right)
    {
        Node *pred = curr->left;
        Node *predParent = curr;
        while (pred->right)
        {
            predParent = pred;
            pred = pred->right;
        }
        curr->data = pred->data;
        curr = pred;
        parent = predParent;
    }
    Node *child = (curr->left) ? curr->left : curr->right;
    if (parent == NULL)
    {
        root = child;
    }
    else if (parent->left == curr)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }
    delete curr;
    return root;
}

void inorder(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int h = 0;
    while (!q.empty())
    {
        int size = q.size();
        h++;
        while (size--)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return h;
}

int totalNodes(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cnt++;
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return cnt;
}

int leafNodes(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->left == NULL && curr->right == NULL)
            cnt++;
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return cnt;
}

int internalNodes(Node *root)
{
    return totalNodes(root) - leafNodes(root);
}

Node *buildBSTFromPreorder(vector<int> &pre)
{
    if (pre.empty())
        return NULL;
    Node *root = new Node(pre[0]);
    stack<Node *> st;
    st.push(root);
    for (int i = 1; i < pre.size(); i++)
    {
        Node *temp = NULL;
        while (!st.empty() && pre[i] > st.top()->data)
        {
            temp = st.top();
            st.pop();
        }
        if (temp)
        {
            temp->right = new Node(pre[i]);
            st.push(temp->right);
        }
        else
        {
            st.top()->left = new Node(pre[i]);
            st.push(st.top()->left);
        }
    }
    return root;
}

Node *buildBSTFromPostorderIterative(vector<int> &post)
{
    if (post.empty())
        return NULL;
    int n = post.size();
    Node *root = new Node(post[n - 1]);
    stack<Node *> st;
    st.push(root);
    for (int i = n - 2; i >= 0; i--)
    {
        Node *temp = NULL;
        while (!st.empty() && post[i] < st.top()->data)
        {
            temp = st.top();
            st.pop();
        }
        if (temp)
        {
            temp->left = new Node(post[i]);
            st.push(temp->left);
        }
        else
        {
            st.top()->right = new Node(post[i]);
            st.push(st.top()->right);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    int choice;
    cout << "Choose BST Construction Method:" <<endl;
    cout << "1. Insert values one by one" <<endl;
    cout << "2. Build from Preorder" << endl;
    cout << "3. Build from Postorder" <<endl;
    cout << "Enter choice: ";
    cin >> choice;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter values:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (choice == 1)
    {
        for (int i = 0; i < n; i++)
            root = insert(root, arr[i]);
    }
    else if (choice == 2)
    {
        root = buildBSTFromPreorder(arr);
    }
    else if (choice == 3)
    {
        root = buildBSTFromPostorderIterative(arr);
    }
    else
    {
        cout << "Invalid choice!"<<endl;
        return 0;
    }
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "Height: " << height(root) << endl;
    cout << "Total Nodes: " << totalNodes(root)<<endl;
    cout << "Leaf Nodes: " << leafNodes(root)<<endl;
    cout << "Internal Nodes: " << internalNodes(root)<<endl;
    cout << "Minimum Value: " << findMin(root)->data <<endl;
    cout << "Maximum Value: " << findMax(root)->data << endl;
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    if (searchIterative(root, key))
        cout << "Found! :D" <<endl;
    else
        cout << "Not Found! :(" <<endl;
    int del;
    cout << "Enter value to delete: ";
    cin >> del;
    root = deleteNode(root, del);
    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;
    return 0;
}
