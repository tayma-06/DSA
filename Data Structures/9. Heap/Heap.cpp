#include <bits/stdc++.h>
using namespace std;

class MaxHeap
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
        heapifyDown(i, heap.size());
    }
    void heapifyDown(int i, int size)
    {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest, size);
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

public:
    MaxHeap() {}
    MaxHeap(vector<int> &arr)
    {
        heap = arr;
        for (int i = (int)heap.size() / 2 - 1; i >= 0; --i)
        {
            heapifyDown(i);
        }
    }
    void insert(int key)
    {
        heap.push_back(key);
        heapifyUp((int)heap.size() - 1);
    }
    int extractMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return maxVal;
    }
    int getMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return heap[0];
    }
    void increaseKey(int i, int newValue)
    {
        if (i < 0 || i >= (int)heap.size())
        {
            cout << "Index out of range" << endl;
            return;
        }
        heap[i] += newValue;
        heapifyUp(i);
    }
    void decreaseKey(int i, int newValue)
    {
        if (i < 0 || i >= (int)heap.size())
        {
            cout << "Index out of range" << endl;
            return;
        }
        heap[i] -= newValue;
        heapifyDown(i);
    }
    int size() { return (int)heap.size(); }
    bool isEmpty() { return heap.empty(); }
    void printHeap()
    {
        cout << "Heap: ";
        for (int val : heap)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    void heapSort()
    {
        int n = (int)heap.size();
        for (int i = n / 2 - 1; i >= 0; --i)
        {
            heapifyDown(i, n);
        }
        for (int i = n - 1; i > 0; --i)
        {
            swap(heap[0], heap[i]);
            heapifyDown(0, i);
        }
    }
    vector<int> sortedArray()
    {
        vector<int> copy = heap;
        for (int i = (int)copy.size() / 2 - 1; i >= 0; --i)
        {
            int size = copy.size();
            int idx = i;
            while (true)
            {
                int largest = idx;
                int left = 2 * idx + 1;
                int right = 2 * idx + 2;
                if (left < size && copy[left] > copy[largest])
                    largest = left;
                if (right < size && copy[right] > copy[largest])
                    largest = right;
                if (largest == idx)
                    break;
                std::swap(copy[idx], copy[largest]);
                idx = largest;
            }
        }
        int n = (int)copy.size();
        for (int i = n - 1; i > 0; --i)
        {
            swap(copy[0], copy[i]);
            int size = i;
            int idx = 0;
            while (true)
            {
                int largest = idx;
                int left = 2 * idx + 1;
                int right = 2 * idx + 2;
                if (left < size && copy[left] > copy[largest])
                    largest = left;
                if (right < size && copy[right] > copy[largest])
                    largest = right;
                if (largest == idx)
                    break;
                std::swap(copy[idx], copy[largest]);
                idx = largest;
            }
        }
        return copy;
    }
};
class MinHeap
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
        int size = (int)heap.size();
        if (left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }
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

public:
    MinHeap() {}
    MinHeap(vector<int> &arr)
    {
        heap = arr;
        for (int i = (int)heap.size() / 2 - 1; i >= 0; --i)
        {
            heapifyDown(i);
        }
    }
    void insert(int key)
    {
        heap.push_back(key);
        heapifyUp((int)heap.size() - 1);
    }
    int extractMin()
    {
        if (heap.empty())
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return minVal;
    }
    int getMin()
    {
        if (heap.empty())
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return heap[0];
    }
    void increaseKey(int i, int newValue)
    {
        if (i < 0 || i >= (int)heap.size())
        {
            cout << "Index out of range" << endl;
            return;
        }
        heap[i] += newValue;
        heapifyDown(i);
    }
    void decreaseKey(int i, int newValue)
    {
        if (i < 0 || i >= (int)heap.size())
        {
            cout << "Index out of range" << endl;
            return;
        }
        heap[i] -= newValue;
        heapifyUp(i);
    }
    int size() { return (int)heap.size(); }
    bool isEmpty() { return heap.empty(); }
    void printHeap()
    {
        cout << "Heap: ";
        for (int val : heap)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main()
{
    vector<int> arr = {10, 3, 5, 30, 2, 8};
    cout << "Using MaxHeap: " << endl;
    MaxHeap maxH(arr);
    maxH.printHeap();
    maxH.heapSort();
    cout << "After heapSort (ascending): " << endl;
    maxH.printHeap();
    cout << endl;
    cout << "Using MinHeap: " << endl;
    MinHeap minH(arr);
    minH.printHeap();
    cout << "Min element: " << minH.getMin() << endl;
    return 0;
}
