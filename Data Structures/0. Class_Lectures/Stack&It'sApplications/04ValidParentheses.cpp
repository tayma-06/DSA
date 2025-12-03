#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                cout << "Not Possible" << endl;
                return 0;
            }
            if ((ch == ')' && st.top() == '(') ||
                (ch == '}' && st.top() == '{') ||
                (ch == ']' && st.top() == '['))
            {
                st.pop();
            }
            else
            {
                cout << "Not Possible" << endl;
                return 0;
            }
        }
    }
    if (st.empty())
        cout << "Possible" << endl;
    else
        cout << "Not Possible" << endl;
    return 0;
}
