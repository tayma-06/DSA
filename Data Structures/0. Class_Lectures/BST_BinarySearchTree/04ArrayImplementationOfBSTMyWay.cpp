#include <bits/stdc++.h>
using namespace std;

class BSTArray
{
    int *bst;
    int capacity;
public:
    BSTArray(int cap)
    {
        capacity = cap;
        bst = new int[capacity];
        for (int i = 0; i < capacity; i++)
            bst[i] = -1;
    }

    void insert(int index, int val)
    {
        if (index >= capacity)
        {
            cout << "Tree overflow\n";
            return;
        }
        if (bst[index] == -1)
        {
            bst[index] = val;
            return;
        }
        if (val < bst[index])
            insert(2 * index + 1, val);
        else if (val > bst[index])
            insert(2 * index + 2, val);
    }

    bool search(int index, int key)
    {
        if (index >= capacity || bst[index] == -1)
            return false;
        if (bst[index] == key)
            return true;
        if (key < bst[index])
            return search(2 * index + 1, key);
        else
            return search(2 * index + 2, key);
    }

    int height(int index)
    {
        if (index >= capacity || bst[index] == -1)
            return 0;
        return 1 + max(height(2 * index + 1), height(2 * index + 2));
    }

    int totalNodes(int index)
    {
        if (index >= capacity || bst[index] == -1)
            return 0;
        return 1 + totalNodes(2 * index + 1) + totalNodes(2 * index + 2);
    }

    int totalExternalNodes(int index)
    {
        if (index >= capacity || bst[index] == -1)
            return 0;
        if ((2 * index + 1 >= capacity || bst[2 * index + 1] == -1) && (2 * index + 2 >= capacity || bst[2 * index + 2] == -1))
            return 1;
        return totalExternalNodes(2 * index + 1) + totalExternalNodes(2 * index + 2);
    }

    int totalInternalNodes(int index)
    {
        if (index >= capacity || bst[index] == -1)
            return 0;
        if ((2 * index + 1 >= capacity || bst[2 * index + 1] == -1) &&
            (2 * index + 2 >= capacity || bst[2 * index + 2] == -1))
            return 0;
        return 1 + totalInternalNodes(2 * index + 1) + totalInternalNodes(2 * index + 2);
    }

    int findMin()
    {
        int index = 0;
        if (bst[index] == -1)
            return -1;
        while (2 * index + 1 < capacity && bst[2 * index + 1] != -1)
            index = 2 * index + 1;
        return bst[index];
    }

    int findMax()
    {
        int index = 0;
        if (bst[index] == -1)
            return -1;
        while (2 * index + 2 < capacity && bst[2 * index + 2] != -1)
            index = 2 * index + 2;
        return bst[index];
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    BSTArray tree(100);
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tree.insert(0, x);
    }
    cout << "Height: " << tree.height(0) << endl;
    cout << "Total nodes: " << tree.totalNodes(0) << endl;
    cout << "Leaf nodes: " << tree.totalExternalNodes(0) << endl;
    cout << "Internal nodes: " << tree.totalInternalNodes(0) << endl;
    cout << "Minimum value: " << tree.findMin() << endl;
    cout << "Maximum value: " << tree.findMax() << endl;
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    if (tree.search(0, key))
        cout << "Found!:D\n";
    else
        cout << "Not Found!:(\n";
    return 0;
}