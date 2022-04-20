/*
Shortest path in undirected graphs with weights
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int vertices;
    bool undirrected;
    vector<pair<int, int>> *adjList;

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
};

int main()
{
    Graph g(5, true);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 1);
    g.addEdge(4, 3, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 5, 5);
    g.addEdge(3, 5, 1);
    g.printGraph();
    return 0;
}