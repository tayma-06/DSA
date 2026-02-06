#include<bits/stdc++.h>
using namespace std;

class Graph1
{
    int V;
    vector<vector<int>> mat;

public:
    Graph1(int v)
    {
        V = v;
        mat.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v)
    {
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
};

class Graph2
{
    int V;
    vector<vector<int>> adj;
    vector<int> vis;

public:
    Graph2(int v)
    {
        V = v;
        adj.resize(V);
        vis.resize(V, 0);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (int x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }

    void bfs(int start)
    {
        fill(vis.begin(), vis.end(), 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int x : adj[curr])
            {
                if (!vis[x])
                {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        cout << endl;
    }

    void dfs(int start)
    {
        fill(vis.begin(), vis.end(), 0);
        stack<int> st;
        st.push(start);
        vis[start] = 1;

        while (!st.empty())
        {
            int curr = st.top();
            st.pop();
            cout << curr << " ";

            for (int x : adj[curr])
            {
                if (!vis[x])
                {
                    vis[x] = 1;
                    st.push(x);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int V;
    cin >> V;

    Graph1 g1(V);
    Graph2 g2(V);

    while (true)
    {
        int choice;
        cin >> choice;

        if (choice == 0)
            break;

        int u, v, start;

        switch (choice)
        {
        case 1:
            cin >> u >> v;
            g1.addEdge(u, v);
            g2.addEdge(u, v);
            break;

        case 2:
            g1.print();
            break;

        case 3:
            g2.print();
            break;

        case 4:
            cin >> start;
            g2.bfs(start);
            break;

        case 5:
            cin >> start;
            g2.dfs(start);
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
