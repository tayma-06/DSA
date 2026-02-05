#include<bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int capacity;
    int top;
public:
    Stack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }
    void push(int val)
    {
        if(top == capacity-1)
        {
            cout << "Overflow" << endl;
            return;
        }
        arr[++top] = val;
    }
    void pop()
    {
        if(top == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        top--;
    }
    int peek()
    {
        return arr[top];
    }
    int size()
    {
        if(empty())
        {
            cout << "Underflow" << endl;
            return 0;
        }
        return top + 1;
    }
    bool full()
    {
        return top == (capacity - 1);
    }
    bool empty()
    {
        return top == -1;
    }
    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cin >> size;
    Stack st(size);
    while(true)
    {
        int choice, val;
        cin >> choice;
        if(choice == 0)
        {
            break;
        }
        switch(choice)
        {
            case 1: // push(val)
                cin >> val;
                st.push(val);
                st.print();
                break;
            case 2: // pop(val)
                st.pop();
                st.print();
                break;
            case 3: // peek
                cout << st.peek() << endl;
                break;
            case 4: // size
                cout << st.size() << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }
}