#include <bits/stdc++.h>
using namespace std;

class Graph
{
    bool undirected;
    vector<int> *adjList;

public:
    int vertices;
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

    // we dont need to do the checking using helper because i am using only a single component
    // of the graph and not a disconnected multiple component graph
    bool checkBipartiteBfs(int source, vector<int> &color)
    {
        queue<int> q;
        q.push(source);
        color[source] = 0;

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto x : adjList[top])
            {
                if (color[x] == -1)
                {
                    q.push(x);
                    color[x] = color[top] == 0 ? 1 : 0;
                }
                else if (color[x] == color[top])
                {
                    return false;
                }
            }
        }
        return true;
    }

    // TC : O(N+E)
    bool checkBipartititeDfs(int source, vector<int> &color)
    {
        for (auto x : adjList[source])
        {
            if (color[x] == -1)
            {
                color[x] = color[source] == 0 ? 1 : 0;
                if (!checkBipartititeDfs(x, color))
                {
                    return false;
                }
            }
            else if (color[x] == color[source])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Graph g(8, true); // nodes , undirected
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 7);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 8);
    g.addEdge(6, 7);
    g.printGraph();

    vector<int> color(g.vertices + 1, -1);
    // cout << g.checkBipartiteBfs(1, color) << endl;
    color[1] = 0;
    cout << g.checkBipartititeDfs(1, color) << endl;

    return 0;
}