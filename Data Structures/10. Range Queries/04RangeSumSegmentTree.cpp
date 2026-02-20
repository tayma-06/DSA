#include <bits/stdc++.h>
using namespace std;
struct SegTree
{
    int n;
    vector<int> tree;
    SegTree(int n) : n(n), tree(4 * n, 0) {}
    void build(vector<int> &arr, int v, int l, int r)
    {
        if (l == r)
        {
            tree[v] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * v, l, mid);
        build(arr, 2 * v + 1, mid + 1, r);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    void update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tree[v] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * v, l, mid, pos, val);
        else
            update(2 * v, mid + 1, r, pos, val);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    int query(int v, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= 1 && r <= qr)
            return tree[v];
        int mid = (l + r) / 2;
        return query(2 * v, l, mid, ql, qr) + query(2 * v + 1, mid + 1, r, ql, qr);
    }
    void build(vector<int> & arr)
    {
        build(arr, 1, 0, n - 1);
    }
    void update(int pos, int val)
    {
        update(1, 0, n - 1, pos, val);
    }
    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();
    SegTree st(n);
    st.build(arr);
    cout << st.query(1, 3) << endl;
    st.update(1, 10);
    cout << st.query(1, 3) << endl;
}