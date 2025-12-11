#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
    {
        return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    int currLevel = 0;
    while (!q.empty())
    {
        int len = q.size();
        res.push_back({});
        for (int i = 0; i < len; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            res[currLevel].push_back(node->val);
            if (node->left != NULL)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        currLevel++;
    }
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

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(12);
    root->right = new TreeNode(13);

    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(14);

    root->right->right = new TreeNode(2);

    root->left->left->left = new TreeNode(17);
    root->left->left->right = new TreeNode(23);

    root->left->right->left = new TreeNode(27);
    root->left->right->right = new TreeNode(3);

    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(11);

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
