#include <bits/stdc++.h>
using namespace std;
struct SegTree
{
    int n;
    vector<int> mn, mx;
    SegTree(int n) : n(n), mn(4 * n, INT_MAX), mx(4 * n, INT_MIN) {}
    void build(vector<int> &arr, int v, int l, int r)
    {
        if (l == r)
        {
            mn[v] = mx[v] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * v, l, mid);
        build(arr, 2 * v + 1, mid + 1, r);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
    void update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            mn[v] = mx[v] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * v, l, mid, pos, val);
        else
            update(2 * v, mid + 1, r, pos, val);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
    int queryMin(int v, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return INT_MAX;
        if (ql <= 1 && r <= qr)
            return mn[v];
        int mid = (l + r) / 2;
        return queryMin(2 * v, l, mid, ql, qr) + queryMin(2 * v + 1, mid + 1, r, ql, qr);
    }
    int queryMax(int v, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return INT_MIN;
        if (ql <= 1 && r <= qr)
            return mn[v];
        int mid = (l + r) / 2;
        return queryMax(2 * v, l, mid, ql, qr) + queryMax(2 * v + 1, mid + 1, r, ql, qr);
    }
    void build(vector<int> &arr)
    {
        build(arr, 1, 0, n - 1);
    }
    void update(int pos, int val)
    {
        update(1, 0, n - 1, pos, val);
    }
    int queryMin(int l, int r)
    {
        return queryMin(1, 0, n - 1, l, r);
    }
    int queryMax(int l, int r)
    {
        return queryMax(1, 0, n - 1, l, r);
    }
};

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();
    SegTree st(n);
    st.build(arr);
    cout << st.queryMin(1, 3) << endl;
    cout << st.queryMax(1, 3) << endl;
    st.update(1, 10);
    cout << st.queryMin(1, 3) << endl;
    cout << st.queryMax(1, 3) << endl;
}