#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isRightAssociativity(char c)
{
    return c == '^';
}

string infixToPostfix(string s)
{
    string postfix = "";
    s = "(" + s + ")";
    stack<char> st;
    if (s.empty())
    {
        return "Invalid Operation";
    }
    for (char ch : s)
    {
        if (ch == '(')
            st.push(ch);
        else if (('A' >= ch && 'Z' <= ch) || ('a' >= ch && 'z' <= ch) || ('0' <= ch && '9' >= ch))
        {
            postfix += ch;
        }
        if (ch == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
        {
            while((precedence(ch) < precedence(st.top())) ||( !isRightAssociativity(ch) && precedence(ch) == precedence(st.top())))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    return postfix;
}

int main()
{
    string s;
    cin >> s;
    cout << infixToPostfix(s) << endl;
    return 0;
}