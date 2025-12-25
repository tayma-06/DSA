#include <bits/stdc++.h>
using namespace std;

class Vertex
{
public:
    int data;
    Edge *firstOut;
    Vertex(int d = 0)
    {
        data = d;
        firstOut = NULL;
    }
};

class Edge
{
public:
    int from, to;
    Edge *nextOut;
    Edge(int f, int t)
    {
        from = f;
        to = t;
        nextOut = NULL;
    }
};

class GraphOrthogonal
{
    int V;
    vector<Vertex> vertices;

public:
    GraphOrthogonal(int V)
    {
        this->V = V;
        vertices.resize(V);
        for (int i = 0; i < V; i++)
            vertices[i] = Vertex(i);
    }
    void addEdge(int u, int v)
    {
        Edge *e = new Edge(u, v);
        e->nextOut = vertices[u].firstOut;
        vertices[u].firstOut = e;
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
                Edge *e = vertices[u].firstOut;
                vector<int> nbrs;
                while (e)
                {
                    if (!vis[e->to])
                        nbrs.push_back(e->to);
                    e = e->nextOut;
                }
                for (int i = nbrs.size() - 1; i >= 0; i--)
                    st.push(nbrs[i]);
            }
        }
    }
};

int main()
{
    GraphOrthogonal g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.DFS(0);
}
