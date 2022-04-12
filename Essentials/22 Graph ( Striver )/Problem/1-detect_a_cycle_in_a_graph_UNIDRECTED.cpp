#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    bool undirected;
    vector<int> *adjList;

public:
    Graph(int number_of_vertices, bool dir)
    {
        this->vertices = number_of_vertices;
        this->undirected = dir;
        adjList = new vector<int>[vertices + 1];
    }

    void addEdge(int a, int b)
    {
        adjList[a].push_back(b);
        if (undirected)
        {
            adjList[b].push_back(a);
        }
    }

    void printGraph()
    {
        cout << "AdjList : " << endl;
        for (int i = 1; i <= vertices; i++)
        {
            cout << i << " --> ";
            for (auto x : adjList[i])
            {
                cout << x << " , ";
            }
            cout << endl;
        }
    }

    bool bfsHelperUndir(int source, vector<int> &visited)
    {
        queue<pair<int, int>> q; // main node and the parent node in pair
        q.push({source, -1});
        visited[source] = 1;

        while (!q.empty())
        {
            auto top = q.front().first;
            auto parent = q.front().second;
            q.pop();
            for (auto x : adjList[top])
            {
                if (visited[x] == 0)
                {
                    q.push({x, top});
                    visited[x] = 1;
                }
                else if (parent != x)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool detectcycleUndirBfs()
    {
        vector<int> visited(vertices + 1, 0);
        for (int i = 1; i <= vertices; i++)
        {
            if (visited[i] == 0)
            {
                if (bfsHelperUndir(i, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfsHelperUndir(int source, int parent, vector<int> &visited)
    {
        visited[source] = 1;
        for (auto x : adjList[source])
        {
            if (visited[x] == 0)
            {
                if (dfsHelperUndir(x, source, visited))
                {
                    return true;
                }
            }
            else if (x != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool detectCycleUndirDfs()
    {
        vector<int> visited(vertices + 1, 0);
        for (int i = 1; i < vertices; i++)
        {
            if (visited[i] == 0)
            {
                if (dfsHelperUndir(i, -1, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(11, true); // nodes , undirected
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 10);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(8, 11);
    g.addEdge(10, 9);

    g.printGraph();

    cout << g.detectCycleUndirDfs() << endl;
    return 0;
}