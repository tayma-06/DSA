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
        // Undirected Graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    GraphMatrix g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.print();
    return 0;
}