#include <bits//stdc++.h>
using namespace std;

class MaxHeapify
{
private:
    vector<int> heap;
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int leftChild(int i)
    {
        return 2 * i + 1;
    }
    int rightChild(int i)
    {
        return 2 * i + 2;
    }
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void heapifyDown(int i)
    {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int size = heap.size();
        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    void heapifyUp(int i)
    {
        while (i > 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};