#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int bst[MAX];
int sizeBST = MAX;

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        bst[i] = -1;
    }
}

void insert(int index, int val)
{
    if (index >= MAX)
    {
        cout << "Tree overflow" << endl;
        return;
    }
    if (val < bst[index])
    {
        insert(2 * index + 1, val);
    }
    else if (val > bst[index])
    {
        insert(2 * index + 2, val);
    }
}

bool search(int index, int key)
{
    if (index >= MAX || bst[index] == -1)
    {
        return false;
    }
    if (bst[index] == key)
    {
        return true;
    }
    if (key < bst[index])
    {
        return search(2 * index + 1, key);
    }
    else
    {
        return search(2 * index + 2, key);
    }
}

int height(int index)
{
    if (index >= MAX || bst[index] == -1)
    {
        return 0;
    }
    return max(height(2 * index + 1), height(2 * index + 2)) + 1;
}

int totalNodes(int index)
{
    if (index >= MAX || bst[index] == -1)
    {
        return 0;
    }
    return 1 + totalNodes(2 * index + 1) + totalNodes(2 * index + 2);
}

int totalExternalNodes(int index)
{
    if (index >= MAX || bst[index] == -1)
    {
        return 0;
    }
    if (bst[2 * index + 1] == -1 && bst[2 * index + 2] == -1)
    {
        return 1;
    }
    return totalExternalNodes(2 * index + 1) + totalExternalNodes(2 * index + 2);
}

int totalInternalNodes(int index)
{
    if (index >= MAX || bst[index] == -1)
    {
        return 0;
    }
    if (bst[2 * index + 1] == -1 && bst[2 * index + 2] == -1)
    {
        return 0;
    }
    return 1 + totalInternalNodes(2 * index + 1) + totalInternalNodes(2 * index + 2);
}

int findMin(int index)
{
    if (bst[index] == -1)
    {
        return -1;
    }
    while (2 * index + 1 < MAX && bst[2 * index + 1] != -1)
    {
        index = 2 * index + 1;
    }
    return bst[index];
}

int findMax(int index)
{
    if (bst[index] == -1)
    {
        return -1;
    }
    while (2 * index + 2 < MAX && bst[2 * index + 2] != -1)
    {
        index = 2 * index + 2;
    }
    return bst[index];
}

int main()
{
    init();
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(0, x);
    }
    cout << "Height: " << height(0) << endl;
    cout << "Total nodes: " << totalNodes(0) << endl;
    cout << "Leaf nodes: " << totalExternalNodes(0) << endl;
    cout << "Internal nodes: " << totalInternalNodes(0) << endl;
    cout << "Minimum value: " << findMin(0) << endl;
    cout << "Maximum value: " << findMax(0) << endl;
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    if (search(0, key))
        cout << "Found! :D" << endl;
    else
    {
        cout << "Not Found! :(" << endl;
    }
    return 0;
}