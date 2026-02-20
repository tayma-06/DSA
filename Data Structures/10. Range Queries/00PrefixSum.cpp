#include <bits/stdc++.h>
using namespace std;

struct PrefixSum
{
    vector<int> pre;
    PrefixSum(vector<int> &arr)
    {
        int n = arr.size();
        pre.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + arr[i];
        }
    }
    int query(int l, int r)
    {
        return pre[r + 1] - pre[l];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    PrefixSum ps(arr);
    int q;
    cin >> q;
    while (q--)
    {
        cout << "Query: ";
        int l, r;
        cin >> l >> r;
        cout << "Result: ";
        cout << ps.query(l, r) << endl;
    }
    return 0;
}