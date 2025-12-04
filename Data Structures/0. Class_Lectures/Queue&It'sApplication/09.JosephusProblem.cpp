#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (q.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

int main()
{
    int n, k;
    cout << "Enter number of people (n): ";
    cin >> n;
    cout << "Enter step count (k): ";
    cin >> k;
    cout << "Survivor: " << josephus(n, k) << endl;
    return 0;
}