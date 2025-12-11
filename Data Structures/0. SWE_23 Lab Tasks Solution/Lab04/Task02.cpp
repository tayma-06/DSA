#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Task 02" << endl;
    deque<char> dq;
    string s;
    getline(cin, s);
    for(char ch : s)
    {
        if(ch !=' ')
        {
            dq.push_back(tolower(ch));
        }
    }
    // for(char ch: dq)
    // {
    //     cout << ch << endl;
    // }
    
    while(!dq.empty())
    {
        if(dq.front() == dq.back())
        {
            dq.pop_front();
            if(!dq.empty())
            dq.pop_back();
        }
        else
        {
            cout << "No palindrome" << endl;
            return 0;
        }
    }
    cout << "Palindrome" << endl;
    return 0;
}