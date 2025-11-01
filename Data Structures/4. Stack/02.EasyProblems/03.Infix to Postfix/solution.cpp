#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

bool isRightAssociative(char c)
{
    return c == '^';
}

string infixToPostfix(string &s)
{
    string postfix;
    stack<char> st;
    for (char ch : s)
    {
        if (isOperand(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && st.top() != '(' && (precedence(st.top()) > precedence(ch) || (precedence(st.top()) == precedence(ch) && !isRightAssociative(ch))))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string exp = "a*(b+c)/d";
    cout << infixToPostfix(exp);
    return 0;
}