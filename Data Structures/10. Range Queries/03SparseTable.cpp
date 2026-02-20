#include <bits/stdc++.h>
using namespace std;

class SparseTable
{
public:
    vector<vector<int>> st;
    vector<int> log;

    SparseTable(const vector<int> &arr)
    {
        int n = arr.size();
        int max_log = log2(n) + 1;

        st.resize(n, vector<int>(max_log));
        log.resize(n + 1);

        log[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            log[i] = log[i / 2] + 1;
        }

        for (int i = 0; i < n; i++)
        {
            st[i][0] = arr[i];
        }

        for (int j = 1; (1 << j) <= n; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        } 
    }

    int query(int l, int r)
    {
        int len = r - l + 1;
        int k = log[len];
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

int main()
{
    vector<int> arr = {1, 3, 2, 7, 9, 11, 5, 6};
    SparseTable st(arr);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << endl;
    }

    return 0;
}