#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        stack<string> web;
        stack<string> temp;
        web.push("http://www.lightoj.com/");
        cout << web.top();
        while (1)
        {
            string command;
            cin >> command;
            if (command == "VISIT")
            {
                string website;
                cin >> website;
                web.push(website);
                cout << web.top();
            }
            if (command == "BACK")
            {
                if (!web.empty())
                {
                    temp.push(web.top());
                    web.pop();
                    cout << web.top() << endl;
                }
                else
                {
                    cout << "IGNORED" << endl;
                }
            }
            if (command == "FORWARD")
            {
                if (!temp.empty())
                {
                    cout << temp.top();
                    web.push(temp.top());
                    temp.pop();
                }
                else
                {
                    cout << "IGNORED" << endl;
                }
            }
            if (command == "QUIT")
            {
                cout << "QUIT" << endl;
                break;
            }
        }
    }
    return 0;
}