#include <bits/stdc++.h>
using namespace std;

class GraphList
{
    int V;
    vector<list<int>> adj;

public:
    GraphList(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void BFS(int src)
    {
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(src);
        vis[src] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    void DFS_helper(int u, vector<bool> &vis)
    {
        vis[u] = true;
        cout << u << " ";

        for (int v : adj[u])
            if (!vis[v])
                DFS_helper(v, vis);
    }
    void DFS(int src)
    {
        vector<bool> vis(V, false);
        DFS_helper(src, vis);
    }
};
int main()
{
    GraphList g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    cout << "BFS: ";
    g.BFS(0);
    cout << endl;
    cout << "DFS: ";
    g.DFS(0);
}
