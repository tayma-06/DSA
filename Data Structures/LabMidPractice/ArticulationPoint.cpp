#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;
    vector<int> disc, low, parent;
    vector<bool> visited, isAP;
    int timer;
    void dfs(int u)
    {
        visited[u] = true;
        disc[u] = low[u] = ++timer;
        int children = 0;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                children++;
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if (parent[u] == -1 && children > 1)
                    isAP[u] = true;
                if (parent[u] != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }
            else if (v != parent[u])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    Graph(int v)
    {
        V = v;
        adj.resize(V);
        disc.resize(V);
        low.resize(V);
        parent.assign(V, -1);
        visited.assign(V, false);
        isAP.assign(V, false);
        timer = 0;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void articulationPoints()
    {
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs(i);
        cout << "Articulation Points: ";
        bool found = false;
        for (int i = 0; i < V; i++)
        {
            if (isAP[i])
            {
                cout << i << " ";
                found = true;
            }
        }
        if (!found)
            cout << "None";
        cout << endl;
    }
};
int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.articulationPoints();
    return 0;
}