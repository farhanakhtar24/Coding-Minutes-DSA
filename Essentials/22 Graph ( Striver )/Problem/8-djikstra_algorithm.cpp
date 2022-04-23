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

    // TC : O(NlogN)
    // SC : 2*O(n)
    int djikstra(int source, int destination)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap , pair => (distance , source)
        vector<int> distance(vertices + 1, INT_MAX);
        distance[source] = 0;
        pq.push({0, source});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adjList[node])
            {
                int adjacentNode = it.first;
                int adjacentNodeDistance = it.second;
                if (distance[node] + adjacentNodeDistance < distance[adjacentNode])
                {
                    distance[adjacentNode] = distance[node] + adjacentNodeDistance;
                    pq.push({distance[adjacentNode], adjacentNode});
                }
            }
        }
        return distance[destination] - distance[source];
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
    cout << g.djikstra(4, 2) << endl;
    return 0;
}