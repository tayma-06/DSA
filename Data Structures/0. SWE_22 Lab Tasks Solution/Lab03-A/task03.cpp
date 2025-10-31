#include <iostream>
#include "CircularQueue.h"

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    CircularQueue q(n);
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (q.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            int f = q.getFront();
            q.pop();
            q.push(f);
        }
        q.pop();
    }
    cout << q.getFront() << endl;
}