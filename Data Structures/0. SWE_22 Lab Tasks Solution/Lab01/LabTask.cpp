#include <iostream>
using namespace std;

class myIntSet
{
    int size;
    int arr[100000];

public:
    myIntSet()
    {
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    int getElem(int i)
    {
        return arr[i];
    }
    void insert(int num)
    {
        arr[size] = num;
        size++;
    }
    int find(int num)
    {
        int start = 0, end = size - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] == num)
                return mid;
            else if (arr[mid] < num)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
    bool erase(int num)
    {
        int index = find(num);
        if (index == -1)
        {
            cout << "Not Available So Cannot Be Erased" << endl;
            return false;
        }
        else
        {
            for (int i = index; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            return true;
        }
    }
    bool erase(int indx1, int indx2)
    {
        if (indx1 < 0 || indx2 >= size || indx1 > indx2)
        {
            cout << "Invalid values Could Not resolve" << endl;
            return false;
        }
        else
        {
            for (int i = indx2; i >= indx1; i--)
                erase(arr[i]);
            return true;
        }
    }

    void printInfo(myIntSet mySet)
    {
        cout << "The Data: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    myIntSet test;
    test.insert(1);
    test.insert(2);
    test.insert(3);
    test.insert(4);
    test.insert(5);
    test.printInfo(test);

    if (test.find(2) != -1)
    {
        cout << "Found at index: " << test.find(2) << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    test.erase(5);
    test.printInfo(test);

    test.erase(1, 3);
    test.printInfo(test);
}
