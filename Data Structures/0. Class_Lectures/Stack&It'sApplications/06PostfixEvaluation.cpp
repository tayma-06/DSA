#include <bits/stdc++.h>
using namespace std;

int applyOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw runtime_error("Division by zero!");
        return a / b;
    case '^':
        return pow(a, b);
    }
    return 0;
}

int evaluatePostfix(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // If operand (digit or multi-digit number)
        if (isdigit(ch))
        {
            int num = 0;

            // Handle multi-digit numbers
            while (i < s.length() && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            st.push(num);
            i--; // adjust for extra increment
        }
        // If operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(applyOperation(a, b, ch));
        }
    }

    return st.top();
}

int main()
{
    string postfix;
    cin >> postfix;
    cout << evaluatePostfix(postfix);
    return 0;
}
