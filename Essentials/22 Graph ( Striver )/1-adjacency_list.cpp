#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    vector<int> *adjList; // pointer to the static array of vector<int>
    /*
    adjList structure : the list is a static array with each element being a vector
    {index}=[value associated with ]it
    0,
    1=[...],
    2=[...],
    3=[...],
    4=[...],
    5=[...]
    */

public:
    Graph(int number_of_vert)
    {
        this->vertices = number_of_vert;
        adjList = new vector<int>[vertices + 1]; // static array of vector<int>
    }

    void addEdge(int a, int b)
    {
        adjList[a].push_back(b);
    }

    void printGraph()
    {
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

    void bfsHelper(int source, vector<int> &visited)
    {
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while (!q.empty())
        {
            int top = q.front();
            cout << top << " , ";
            q.pop();
            for (auto neighbour : adjList[top])
            {
                if (visited[neighbour] == 0)
                {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
    }

    // the bfs here is implemented for both connected and disconnected graph(when a graph has multiple components)
    void bfs()
    {
        // TC : O(n)
        // SC : O(n)
        vector<int> visited(vertices + 1, 0);
        for (int i = 1; i <= vertices; i++)
        {
            if (visited[i] == 0)
            {
                bfsHelper(i, visited);
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);

    cout << "AdjList : \n";
    g.printGraph();

    cout << "BFS traversal : ";
    g.bfs();
    return 0;
}