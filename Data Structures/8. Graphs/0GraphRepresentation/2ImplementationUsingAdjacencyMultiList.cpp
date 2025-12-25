#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v;
    Edge *nextU;
    Edge *nextV;
    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
        nextU = nextV = NULL;
    }
};

class Vertex
{
public:
    int data;
    Edge *firstEdge;
    Vertex(int d = 0)
    {
        data = d;
        firstEdge = NULL;
    }
};

class Graph
{
    int V;
    vector<Vertex> vertices;

public:
    Graph(int V)
    {
        this->V = V;
        vertices.resize(V);
        for (int i = 0; i < V; i++)
        {
            vertices[i] = Vertex(i);
        }
    }
    void addEdge(int u, int v)
    {
        // Undirected
        Edge *e = new Edge(u, v);
        e->nextU = vertices[u].firstEdge;
        vertices[u].firstEdge = e;
        e->nextV = vertices[v].firstEdge;
        vertices[v].firstEdge = e;
    }
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << "->";
            Edge *e = vertices[i].firstEdge;
            while (e)
            {
                if (e->u == i)
                {
                    cout << e->v << " ";
                    e = e->nextU;
                }
                else
                {
                    cout << e->u << " ";
                    e = e->nextV;
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.print();
    return 0;
}