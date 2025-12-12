#include <bits/stdc++.h>
using namespace std;

class ArrayBinaryTree
{
private:
    char *tree;
    int capacity;

public:
    ArrayBinaryTree(int size)
    {
        capacity = size;
        tree = new char[capacity];
        for (int i = 0; i < capacity; i++)
            tree[i] = '\0';
    }

    void setRoot(char key)
    {
        if (tree[0] != '\0')
            cout << "Tree already has a root!" << endl;
        else
            tree[0] = key;
    }

    void setLeft(char key, int parent)
    {
        int leftIndex = 2 * parent + 1;
        if (parent >= capacity || tree[parent] == '\0')
            cout << "Cannot set left child at index " << leftIndex << ", parent not found!" << endl;
        else if (leftIndex >= capacity)
            cout << "Left child index " << leftIndex << " exceeds capacity!" << endl;
        else
            tree[leftIndex] = key;
    }

    void setRight(char key, int parent)
    {
        int rightIndex = 2 * parent + 2;
        if (parent >= capacity || tree[parent] == '\0')
            cout << "Cannot set right child at index " << rightIndex << ", parent not found!" << endl;
        else if (rightIndex >= capacity)
            cout << "Right child index " << rightIndex << " exceeds capacity!" << endl;
        else
            tree[rightIndex] = key;
    }

    void printTree()
    {
        cout << "\nTree elements: ";
        for (int i = 0; i < capacity; i++)
        {
            if (tree[i] != '\0')
                cout << tree[i] << " ";
        }
        cout << endl;
    }

    void inOrder(int index)
    {
        if (index >= capacity || tree[index] == '\0')
            return;
        inOrder(2 * index + 1);     // Left
        cout << tree[index] << " "; // Root
        inOrder(2 * index + 2);     // Right
    }

    void preOrder(int index)
    {
        if (index >= capacity || tree[index] == '\0')
            return;
        cout << tree[index] << " "; // Root
        preOrder(2 * index + 1);    // Left
        preOrder(2 * index + 2);    // Right
    }

    void postOrder(int index)
    {
        if (index >= capacity || tree[index] == '\0')
            return;
        postOrder(2 * index + 1);   // Left
        postOrder(2 * index + 2);   // Right
        cout << tree[index] << " "; // Root
    }

    void levelOrder()
    {
        cout << "Level Order: ";
        for (int i = 0; i < capacity; i++)
        {
            if (tree[i] != '\0')
                cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ArrayBinaryTree t(15);

    t.setRoot('A');
    t.setLeft('B', 0);
    t.setRight('C', 0);
    t.setLeft('D', 1);
    t.setRight('E', 1);
    t.setRight('F', 2);

    t.printTree(); 

    cout << "Inorder: ";
    t.inOrder(0);
    cout << endl;
    cout << "Preorder: ";
    t.preOrder(0);
    cout << endl;
    cout << "Postorder: ";
    cout << endl;
    t.postOrder(0);
    t.levelOrder();
    return 0;
}
