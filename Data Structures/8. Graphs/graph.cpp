// Graph is basically a network of nodes
// Every connection between the nodes are called edges
// The nodes are known as vertices
// Practical Usage: Google map, Uber etc
// A->B->C->D->B->A->C this kind of traversing
// Frindship in Social Media can also be implemented using Graphs
// To implement neural network we may use graph

#include <bits/stdc++.h>
using namespace std;

// Types of graphs: edges -> two kinds of directions: uni directional, undirectional
// Unidirectional : Directed un a direction
// Undirected : No direction or may be called bidirected, i.e. directed both ways
// Weighted Graph : value assigned or associated with the edge
// For example the distance between two cities may be 10km which is associated with edges
// undirected weighted, undirected unweighted, directed weighted, undirected unweighted
// connected graph

// Representation : Adjacency List (Store neighbours for all vertices)

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjacencyList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for(int neigh: l[i])
            {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.printAdjacencyList();
    return 0;
}
