#include<bits/stdc++.h>
using namespace std;

class GraphList
{
    int V;
    list<int> *adj;
    public:
    GraphList(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        // Undirected Graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print()
    {
        for (int i = 0; i<V; i++)
        {
            cout << i << "->";
            for(int v:adj[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    GraphList g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.print();
    return 0;
}