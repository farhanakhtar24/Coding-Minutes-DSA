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

    bool detectCycle()
    {
        vector<int> indegree(vertices, 0);
        for (int i = 0; i < vertices; i++)
        {
            for (auto x : adjList[i])
            {
                // if()
                indegree[x]++;
            }
        }

        queue<int> sortedQ;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                sortedQ.push(i);
            }
        }

        int cnt = 0;
        while (!sortedQ.empty())
        {
            auto top = sortedQ.front();
            sortedQ.pop();
            cnt++;
            for (auto x : adjList[top])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    sortedQ.push(x);
                }
            }
        }

        if (cnt == vertices)
        {
            return false; // as topo sort is only applicable for DAG and not for cyclic directed graphs
        }
        return true;
    }
};

int main()
{
    Graph g(6, false);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.printGraph();
    // if 0 then algo is correct
    cout << g.detectCycle() << endl;
    return 0;
}