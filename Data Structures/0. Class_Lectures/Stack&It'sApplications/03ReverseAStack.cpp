#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    // Method 1: Print by copying to another container
    stack<int> temp = st;
    cout << "Original stack (top to bottom): ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Method 2: Reverse the stack using another stack
    stack<int> reversed;
    temp = st; // Make a copy
    while (!temp.empty())
    {
        reversed.push(temp.top());
        temp.pop();
    }

    cout << "Reversed stack (top to bottom): ";
    temp = reversed;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}