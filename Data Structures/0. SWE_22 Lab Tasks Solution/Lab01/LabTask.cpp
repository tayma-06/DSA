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
        arr[size]=num;
        size++;
    }
    int find(int num)
    {
        int start=0, end=size-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]==num)
                return mid;
            else if(arr[mid]<num)
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    bool erase(int num)
    {
        int indx=find(num);
        if(indx==-1)
            return false;
        for(int i=indx;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
        return true;
    }
    bool erase(int indx1, int indx2)
    {
        if(indx1<0 || indx2>=size || indx1>indx2)
            return false;
        int count=indx2-indx1+1;
        for(int i=indx1;i<size-count;i++)
        {
            arr[i]=arr[i+count];
        }
        size-=count;
        return true;
    }
};

int main()
{
    myIntSet s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);

    cout << "Set elements after insertion: ";
    for(int i=0; i<s.getSize(); i++)
        cout << s.getElem(i) << " ";
    cout << endl;

    s.erase(30);
    cout << "Set elements after erasing 30: ";
    for(int i=0; i<s.getSize(); i++)
        cout << s.getElem(i) << " ";
    cout << endl;

    s.erase(1, 2);
    cout << "Set elements after erasing indices 1 to 2: ";
    for(int i=0; i<s.getSize(); i++)
        cout << s.getElem(i) << " ";
    cout << endl;

    return 0;
}