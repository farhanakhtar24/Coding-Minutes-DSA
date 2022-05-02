#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int parent[100000];
int rRank[100000];

void makeSet(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rRank[i] = 0;
    }
}

int findParent(int node)
{
    if (node == parent[node])
    {
        return node;
    }

    return findParent(parent[node]);
}

void unoin(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if (rRank[u] < rRank[v])
    {
        parent[u] = v;
    }
    else if (rRank[v] < rRank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rRank[u]++;
    }
}

int main()
{
    int m;
    cin >> m;
    makeSet(m);
    while (m--)
    {
        int u, v;
        unoin(u, v);
    }
    if (findParent(2) != findParent(3))
    {
        cout << "Different component" << endl;
    }
    else
    {
        cout << "Same component" << endl;
    }
    return 0;
}