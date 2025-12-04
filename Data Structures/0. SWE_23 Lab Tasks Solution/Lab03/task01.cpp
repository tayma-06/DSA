//Implementation with array
#include<bits/stdc++.h>
using namespace std;

class myStack
{
    int *arr;
    int capacity;
    int top;

    public:
    myStack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }
    void push(int val)
    {
        if(top==capacity-1)
        {
            cout << "stack overflow"<<endl;
            return;
        }
        arr[++top] = val;
    }
    void pop()
    {
        if(top==-1)
        {
            cout << "stack underflow" << endl;
            return;
        }
        top--;
    }
    int peek()
    {
        if(top==-1)
        {
            return -1;
        }
        return arr[top];
    }
    int size()
    {
        return top+1;
    }
    void display()
    {
        if(size()==0)
        {
            cout << "stack underflow" << endl;
            return;
        }
        for(int i=0; i<size(); i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    myStack st(10);
    st.push(10);
    st.push(20);

    st.display();

    cout << st.peek() << endl;
    cout << st.size() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    return 0;
}