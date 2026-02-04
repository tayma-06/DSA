#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (int v : adj[i])
            {
                cout << v << " ";
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
    g.printGraph();
    return 0;
}