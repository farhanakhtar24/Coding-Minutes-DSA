#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int vertices;
    bool undirrected;
    vector<pair<int, int>> *adjList;

    void dfshelper(int i, vector<int> &visited, stack<int> &s)
    {
        visited[i] = 1;
        for (auto x : adjList[i])
        {
            if (visited[x.first] == 0)
            {
                dfshelper(x.first, visited, s);
            }
        }
        s.push(i);
    }

    void topoDFS(stack<int> &s)
    {
        vector<int> visited(vertices, 0);
        for (int i = 0; i < vertices; i++)
        {
            if (visited[i] == 0)
            {
                dfshelper(i, visited, s);
            }
        }
    }

public:
    Graph(int verts, bool dir)
    {
        this->vertices = verts;
        this->undirrected = dir;
        this->adjList = new vector<pair<int, int>>[vertices];
    }

    void addEdge(int a, int b, int weight)
    {
        adjList[a].push_back({b, weight});
        if (undirrected)
        {
            adjList[b].push_back({a, weight});
        }
    }

    void printGraph()
    {
        cout << "AdjList : " << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " --> ";
            for (auto x : adjList[i])
            {
                cout << "(" << x.first << " ," << x.second << ") ,";
            }
            cout << endl;
        }
    }

    // TC : O(N+E) * 2
    // SC : O(2N)
    // ASC : only for DFS soln

    int shortestDistanceInDAG(int source, int destination)
    {
        stack<int> topoStack;
        topoDFS(topoStack);

        vector<int> distance(vertices, INT_MAX);
        distance[source] = 0;
        while (!topoStack.empty())
        {
            auto top = topoStack.top();
            topoStack.pop();
            if (distance[top] != INT_MAX) // add this if block otherwise , this algo will not work
            {
                for (auto x : adjList[top])
                {
                    if (distance[top] + x.second < distance[x.first])
                    {
                        distance[x.first] = distance[top] + x.second;
                    }
                }
            }
        }
        return distance[destination] - distance[source];
    }
};

int main()
{
    Graph g(6, false);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(2, 3, 6);
    g.addEdge(4, 5, 4);
    g.addEdge(5, 3, 1);
    g.printGraph();
    cout << g.shortestDistanceInDAG(1, 2) << endl;
    return 0;
}