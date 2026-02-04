#include <bits/stdc++.h>
using namespace std;

class BST
{
    int *arr;
    int size;
    int capacity;

public:
    BST(int n)
    {
        capacity = n;
        size = 0;
        arr = new int[n];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = -1;
        }
    }

    void insert(int index, int val)
    {
        if (index >= capacity)
        {
            return;
        }

        if (arr[index] == -1)
        {
            arr[index] = val;
            size++;
            return;
        }

        if (val < arr[index])
        {
            insert(2 * index + 1, val);
        }
        else
        {
            insert(2 * index + 2, val);
        }
    }

    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (arr[i] != -1)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    BST bst(31);

    bst.insert(0, 50);
    bst.insert(0, 30);
    bst.insert(0, 70);

    bst.print();

    return 0;
}
