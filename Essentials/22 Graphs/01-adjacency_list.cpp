#include <bits/stdc++.h>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int vertices)
    {
        this->V = vertices;
        l = new list<int>[V];
        // actual statement that is being executed here => list *l = new list<int> [V]
    }
    void addEdge(int i, int j, bool undir = false)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printList()
    {
        /// iterate over all the rows
        for (int i = 0; i < V; i++)
        {
            cout << i << " --> ";
            for (auto node : l[i])
            {
                cout << node << " , ";
            }
            cout << endl;
        }
    }

    // bfs is always iterative .i.e. it is implemented using a stack or queue
    // T.C : O(V+E)
    void bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            int f = q.front();
            cout << f << endl;
            q.pop();
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    // dfs is always recursive .i.e. it is implemented using recursion/backtracking
    // T.C : O(V+E)
    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << ",";
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
    }

    void topologicalOrdering() // Kahn's Algorithm
    {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();
            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.topologicalOrdering();

    // g.addEdge(0, 1);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 5);
    // g.addEdge(5, 6);
    // g.addEdge(4, 5);
    // g.addEdge(0, 4);
    // g.addEdge(3, 4);
    // g.printList();

    // g.bfs(1);
    // g.dfs(1);
    return 0;
}