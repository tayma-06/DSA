// dfs = depth first search
//  keep going to first unvisited neighbour
//  recursive
//  explicit stack

#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;
        for (int v : l[u])
        {
            if (!vis[v])
                dfsHelper(v, vis);
        }
    }

    void dfs()
    {
        int src = 0;
        vector<bool> vis(V, false);

        dfsHelper(src, vis);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.dfs();
}
