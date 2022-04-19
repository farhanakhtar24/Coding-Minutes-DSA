/*
Whenever ther is an undir graph we assume there are no edge weights , we assign the edge weights as 1
*/

#include <iostream>
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
        this->adjList = new vector<int>[vertices];
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

        for (int i = 0; i < vertices; i++)
        {
            cout << i << " --> ";
            for (auto x : adjList[i])
            {
                cout << x << ", ";
            }
            cout << endl;
        }
    }

    // TC :O(N+E)
    // TC :O(N)+O(N)

    void shortestDistance(int source, int destination)
    {
        vector<int> distance(vertices, INT_MAX);
        queue<int> q;
        q.push(source);
        distance[source] = 0;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto x : adjList[top])
            {
                if (distance[top] + 1 < distance[x])
                {
                    distance[x] = distance[top] + 1;
                    q.push(x);
                }
            }
        }
        cout << distance[destination] - distance[source] << endl;
    }
};

int main()
{
    Graph g(9, true);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);
    g.printGraph();
    g.shortestDistance(2, 8);
    return 0;
}