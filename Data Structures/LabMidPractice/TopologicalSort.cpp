#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    stack<int> st;
    void dfs(int u)
    {
        visited[u] = true;
        for (int v : adj[u])
            if (!visited[v])
                dfs(v);
        st.push(u);
    }

public:
    Graph(int v)
    {
        V = v;
        adj.resize(V);
        visited.assign(V, false);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void topoSort()
    {
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs(i);
        cout << "Topological Order: ";
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topoSort();
    return 0;
}
