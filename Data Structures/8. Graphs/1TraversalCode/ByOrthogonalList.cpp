#include <bits/stdc++.h>
using namespace std;

class Edge;

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
            Edge *e = vertices[u].firstOut;
            while (e)
            {
                int v = e->to;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
                e = e->nextOut;
            }
        }
    }
    void DFSUtil(int u, vector<bool> &vis)
    {
        vis[u] = true;
        cout << u << " ";
        Edge *e = vertices[u].firstOut;
        while (e)
        {
            int v = e->to;
            if (!vis[v])
                DFSUtil(v, vis);
            e = e->nextOut;
        }
    }
    void DFS(int src)
    {
        vector<bool> vis(V, false);
        DFSUtil(src, vis);
    }
};
int main()
{
    GraphOrthogonal g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    cout << "BFS: ";
    g.BFS(0);
    cout << endl;
    cout << "DFS: ";
    g.DFS(0);
}
