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
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int size = heap.size();
        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;
        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
    void heapifyUp(int i)
    {
        while (i > 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};