#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    bool undirrected;
    vector<int> *adjList;

public:
    Graph(int verts, bool dir)
    {
        this->vertices = verts;
        this->undirrected = dir;
        this->adjList = new vector<int>[vertices + 1];
    }

    void addEdge(int a, int b)
    {
        adjList[a].push_back(b);
        if (undirrected)
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
                cout << x << ", ";
            }
            cout << endl;
        }
    }

    // TC : O(N+E)
    // SC : O(2N)

    bool dfsHelper(int i, vector<int> &visited, vector<int> &dfsVisited)
    {
        visited[i] = 1;
        dfsVisited[i] = 1;

        for (auto x : adjList[i])
        {
            if (visited[x] == 0)
            {
                if (dfsHelper(x, visited, dfsVisited))
                {
                    return true;
                }
            }
            else if (visited[x] == 1 && dfsVisited[x] == 1)
            {
                return true;
            }
        }
        dfsVisited[i] = 0;
        return false;
    }

    bool detectCycleDFS()
    {
        vector<int> visited(vertices + 1, 0);
        vector<int> dfsVisited(vertices + 1, 0);
        for (int i = 1; i <= vertices; i++)
        {
            if (!visited[i])
            {
                if (dfsHelper(i, visited, dfsVisited))
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
    Graph g(9, false);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(4, 5);
    g.addEdge(6, 5);
    g.addEdge(7, 2);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(9, 7);
    g.printGraph();
    cout << g.detectCycleDFS() << endl;
    return 0;
}