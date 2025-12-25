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
                for (auto it = adj[u].rbegin(); it != adj[u].rend(); it++)
                {
                    if (!vis[*it])
                        st.push(*it);
                }
            }
        }
    }
};

int main()
{
    GraphList g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.DFS(0);
}
