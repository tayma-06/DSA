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
    s = "(" + s + ")"; // Add parenthesis around whole string
    stack<char> st;
    string postfix = "";

    for (char ch : s)
    {
        // If operand, add to postfix
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // If '(' push to stack
        else if (ch == '(')
        {
            st.push(ch);
        }
        // If operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                    (precedence(st.top()) == precedence(ch) && !isRightAssociativity(ch))))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
    }

    return postfix;
}

int main()
{
    string exp;
    cin >> exp;
    cout << infixToPostfix(exp) << endl;
    return 0;
}
