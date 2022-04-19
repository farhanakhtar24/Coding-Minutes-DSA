/*
Topo sort :linear ordering of vertices such that if there is an edge u->v, u appears before v in that ordering
Topological sorting can be done for DAG .
Graph should always be directed
*/

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

    void dfsHelper(int i, vector<int> &visited, stack<int> &s)
    {
        visited[i] = 1;
        for (auto x : adjList[i])
        {
            if (visited[x] == 0)
            {
                dfsHelper(x, visited, s);
            }
        }
        s.push(i);
    }

    // TC : O(N+E)
    // SC : O(N)
    // ASC :O(N)

    void topoDFS()
    {
        vector<int> visited(vertices + 1, 0);
        stack<int> s;

        for (int i = 0; i < vertices; i++)
        {
            if (visited[i] == 0)
            {
                dfsHelper(i, visited, s);
            }
        }

        while (!s.empty())
        {
            cout << s.top() << " ,";
            s.pop();
        }
    }

    // TC : O(N+E)
    // SC : O(N)+O(N)

    void topoBFS()
    {
        vector<int> indegreeArray(vertices, 0); // no of directed edges on each node

        for (int i = 0; i < vertices; i++)
        {
            for (auto x : adjList[i])
            {
                indegreeArray[x]++;
            }
        }

        queue<int> sortedQ;
        for (int i = 0; i < vertices; i++)
        {
            if (indegreeArray[i] == 0)
            {
                sortedQ.push(i);
            }
        }

        while (!sortedQ.empty())
        {
            auto top = sortedQ.front();
            cout << top << " ,";
            sortedQ.pop();
            for (auto x : adjList[top])
            {
                indegreeArray[x]--;
                if (indegreeArray[x] == 0)
                {
                    sortedQ.push(x);
                }
            }
        }
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
    cout << "DFS : ";
    g.topoDFS();
    cout << endl;
    cout << "BFS : ";
    g.topoBFS();
    return 0;
}