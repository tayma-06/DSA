// bfs traversal = Breadth First Search
// travel to immediate neighbour first
// when we visit the neighbour we mark or flag them as visited
// track the vertices that are visited
// similar to level order traversal in tree
#include <bits/stdc++.h>
using namespace std;
// we take a queue
// create a boolean value array
// let src_node = u, dest_node = v
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

    void bfs()
    {
        queue<int> Q;
        vector<bool> vis(V, false);
        Q.push(0); // vertex 0 is the source node
        vis[0] = true;

        while (Q.size() > 0)
        {
            int u = Q.front();
            Q.pop();
            cout << u << " ";
            for (int v : l[u]) // immediate neighbours
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.bfs();
}
