#include <bits/stdc++.h>
using namespace std;

class GraphMatrix
{
    int V;
    vector<vector<int>> adj;

public:
    GraphMatrix(int V)
    {
        this->V = V;
        adj.resize(V, vector<int>(V, 0));
    }
    void addEdge(int u, int v)
    {
        adj[u][v] = 1;
    }
    void DFS(int src)
    {
        vector<bool> vis(V, false);
        stack<int> st;
        st.push(src);
        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            if (!vis[u])
            {
                vis[u] = true;
                cout << u << " ";
                for (int v = V - 1; v >= 0; v--)
                {
                    if (adj[u][v] && !vis[v])
                        st.push(v);
                }
            }
        }
    }
};
int main()
{
    GraphMatrix g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.DFS(0);
}
