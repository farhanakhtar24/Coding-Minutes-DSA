/*
There should be n nodes and n-1 edges , every node should be reachable by every other node
MST : Out of all spanning trees possible the tree which has the minimum cost edges is known as the MST.
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
        this->adjList = new vector<pair<int, int>>[vertices + 1];
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
        for (int i = 1; i <= vertices; i++)
        {
            cout << i << " --> ";
            for (auto x : adjList[i])
            {
                cout << "(" << x.first << " ," << x.second << ") ,";
            }
            cout << endl;
        }
    }

    void primsAlgo()
    {
        vector<int> parent(vertices, -1);
        vector<int> key(vertices, INT_MAX);
        vector<bool> mstSet(vertices, false);

        key[0] = 0;
        parent[0] = -1;
    }
};

int main()
{
    Graph g(5, true);
    g.addEdge(5, 4, 9);
    g.addEdge(5, 1, 4);
    g.addEdge(4, 1, 1);
    g.addEdge(4, 2, 3);
    g.addEdge(4, 3, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(3, 2, 3);
    g.printGraph();
    return 0;
}