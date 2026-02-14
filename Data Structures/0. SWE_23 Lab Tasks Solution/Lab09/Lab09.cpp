#include<iostream>
using namespace std;

struct Node
{
    int val=0;
    Node *left=NULL;
    Node *right=NULL;
    int height=1;
    Node(int key)
    {
        val = key;
        left = right = NULL;
    }
};

int get_height(Node* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    return node->height;
}

Node * ll_rotate(Node* A)
{
    cout << "LL Rotation" << endl;
    Node * B = A->left;
    Node* T2 = B->right;
    A->left = T2;
    B->right = A;
    A->height = max(get_height(T2), get_height(A->right))+1;
    B->height = max(get_height(B->left), get_height(A))+1;
    return B;
}

Node * lr_rotate(Node* A)
{
    cout << "LR Rotation" << endl;
    Node* B = A->left;
    Node* C = B->right;
    Node* T2 = C->left;
    Node* T3 = C->right;
    B->right = T2;
    A->left = T3;
    C->left = B;
    C->right = A;
    A->height = max(get_height(T3), get_height(A->right))+1;
    B->height = max(get_height(B->left), get_height(T2))+1;
    C->height = max(get_height(B), get_height(A))+1;
    return C;
}

Node* rr_rotate(Node* A)
{
    cout << "RR Rotation" << endl;
    Node* B = A->right;
    Node* T2 = B->left;
    A->right = T2;
    B->left = A;
    A->height = max(get_height(A->left), get_height(T2))+1;
    B->height = max(get_height(A), get_height(B->right))+1;
    return B;
}

Node* rl_rotate(Node* A)
{
    cout << "RL Rotation" << endl;
    Node* B = A->right;
    Node* C = B->left;
    Node* T2 = C->left;
    Node* T3 = C->right;
    B->left = T3;
    A->right = T2;
    C->left = A;
    C->right = B;
    A->height = max(get_height(A->left), get_height(T2))+1;
    B->height = max(get_height(T3), get_height(B->right))+1;
    C->height = max(get_height(A), get_height(B))+1;
    return C;
}

Node *insert_key(Node* root, int key)
{
    if(root==nullptr)
    {
        return new Node(key);
    }
    if(root->val < key)
    {
        root->right = insert_key(root->right, key);
    }
    else
    {
        root->left = insert_key(root->left, key);
    }
    //return root;
    Node* left = root->left;
    Node* right = root->right;
    int bfact = get_height(left) - get_height(right);
    if(bfact > 1 && key <= left->val)
    {
        root = ll_rotate(root);
    }
    else if(bfact > 1 && key > left->val)
    {
        root = lr_rotate(root);
    }
    else if(bfact < -1 && key > right->val)
    {
        root = rr_rotate(root);
    }
    else if(bfact < -1 && key <= right->val)
    {
        root = rl_rotate(root);
    }
    root->height = max(get_height(root->left), get_height(root->right))+1;
    return root;
}

Node* min_key(Node* cur)
{
    if(cur == nullptr)
    {
        return nullptr;
    }
    if(cur->left == nullptr)
    {
        return cur;
    }
    return min_key(cur->left);
}

Node *delete_key(Node*root, int key)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    if(root->val < key)
    {
        root->right = delete_key(root->right, key);
    }
    else if(root->val > key)
    {
        root->left = delete_key(root->left, key);
    }
    else
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        if(root->left == nullptr)
        {
            Node* right = root->right;
            delete root;
            return right;
        }
        if(root->right == nullptr)
        {
            Node *left = root->left;
            delete root;
            return left;
        }
        Node* minimum = min_key(root->right);
        root->val = minimum->val;
        root->right = delete_key(root->right, root->val);
    }
    Node* left = root->left;
    Node* right = root->right;
    int bfact = get_height(left) - get_height(right);
    if(bfact > 1)
    {
        int leftBfact = get_height(left->left)-get_height(left->right);
        if(leftBfact < 1) // combining r0, r-1
        {
            lr_rotate(root);
        }
        else
        {
            ll_rotate(root);
        }
    }
    if(bfact < -1) // l case
    {
        
    }
    root->height = max(get_height(root->left), get_height(root->right))+1;
    return root;
}

void preOrder(Node * cur)
{
    if(cur == nullptr)
    {
        return;
    }
    cout << cur->val << ' ';
    preOrder(cur->left);
    preOrder(cur->right);
}

int main(void)
{
    Node *avl_root = nullptr;
    avl_root = insert_key(avl_root, 50);
    for(int i=0; i<10; i++)
    {
        int key;
        cin >> key;
        avl_root = insert_key(avl_root, key);
        preOrder(avl_root);
        cout << "---------------------------" << endl;
    }
}
