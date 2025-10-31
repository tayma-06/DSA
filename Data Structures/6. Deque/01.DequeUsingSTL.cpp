#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(3);
    dq.push_back(2);
    dq.push_back(1);

    cout << "DATA: " << endl;

    while (!dq.empty())
    {
        cout << dq.front() << endl;
        dq.pop_front();
    }

    dq.push_front(3);
    dq.push_front(2);
    dq.push_front(1);

    cout << "DATA: " << endl;

    while (!dq.empty())
    {
        cout << dq.back() << endl;
        dq.pop_back();
    }

    return 0;
}