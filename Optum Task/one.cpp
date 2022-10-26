#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int helper(int n, int k)
{
    vector<bool> visited(n, false);
    int lastVisited = 0;
    while (!visited.empty())
    {
        int i = lastVisited;
        while (visited[i] != true)
        {
            if (i >= n)
            {
                // i = ;
            }
            i++;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    helper(n, k);
    return 0;
}