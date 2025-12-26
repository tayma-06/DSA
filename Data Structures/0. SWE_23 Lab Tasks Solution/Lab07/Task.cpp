#include <bits/stdc++.h>
using namespace std;

class Graph1
{
    int V;
    vector<vector<int>> vertices;

public:
    Graph1(int val)
    {
        V = val;
        vertices.resize(V, vector<int>(V));
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                vertices[i][j] = 0;
            }
        }
    }
    void addEdgeMat(int v1, int v2)
    {
        vertices[v1][v2] = 1;
        vertices[v2][v1] = 1;
    }
    void printGraphMat()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << vertices[i][j] << " ";
            }
            cout << endl;
        }
    }
};
class Graph2
{
    vector<vector<int>> vertices;
    int V;

public:
    Graph2(int val)
    {
        V = val;
        vertices.resize(V);
    }
    void addEdgeList(int v1, int v2)
    {
        vertices[v1].push_back(v2);
        vertices[v2].push_back(v1);
    }
    void printGraphList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < vertices[i].size(); j++)
            {
                cout << vertices[i][j] << " ";
            }
            cout << endl;
        }
    }
    void bfs()
    {
        int vis[V] = {0};
        // int distance[V];
        // distance[0] = 0;
        // for(int i=1; i<V; i++)
        // {
        //     distance[i] = -1;
        // }
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (int i = 0; i < vertices[curr].size(); i++)
            {
                if (!vis[vertices[curr][i]])
                {
                    vis[vertices[curr][i]] = 1;
                    q.push(vertices[curr][i]);
                    // distance[i] = distance[curr]+1;
                }
            }
        }
        cout << endl;
    }
    void bfs_shortest_path(int source)
    {
        int vis[V] = {0};
        int distance[V];
        distance[source] = 0;
        for (int i = 0; i < V; i++)
        {
            if (i != source)
                distance[i] = -1;
        }
        queue<int> q;
        vis[source] = 1;
        q.push(0);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < vertices[curr].size(); i++)
            {
                if (!vis[vertices[curr][i]])
                {
                    vis[vertices[curr][i]] = 1;
                    q.push(vertices[curr][i]);
                    distance[vertices[curr][i]] = distance[curr] + 1;
                }
            }
        }
        cout << "Distance from Node " << source << ":" << endl;
        for (int i = 0; i < vertices.size(); i++)
        {
            if (i != source)
            {
                cout << "Node " << i << ": " << distance[i] << endl;
            }
        }
        cout << endl;
    }
    void dfs()
    {
        int vis[V] = {0};
        stack<int> st;
        st.push(0);
        vis[0] = 1;
        while (!st.empty())
        {
            int curr = st.top();
            st.pop();
            cout << curr << " ";
            for (int i = 0; i < vertices[curr].size(); i++)
            {
                if (!vis[vertices[curr][i]])
                {
                    st.push(vertices[curr][i]);
                    vis[vertices[curr][i]] = 1;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int v, e;
    cin >> v >> e;
    Graph1 g(v);
    Graph2 g2(v);
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g.addEdgeMat(v1, v2);
        g2.addEdgeList(v1, v2);
    }
    cout << "Adjacency Matrix: " << endl;
    g.printGraphMat();
    cout << "Adjacency List: " << endl;
    g2.printGraphList();
    cout << "BFS Traversal: ";
    g2.bfs();
    cout << "DFS Traversal: ";
    g2.dfs();
    int src;
    cin >> src;
    g2.bfs_shortest_path(src);
}