#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int countMinSwaps(vector<int> &arr)
{
    int n = arr.size();
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    sort(ap, ap + n);

    vector<bool> visited(n, false);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        // if element is visited
        int oldPosition = ap[i].second;
        if (visited[i] == true || oldPosition == i)
        {
            continue;
        }

        // visiting element for 1st time
        int node = i;
        int cycle = 0;

        while (!visited[node])
        {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle += 1;
        }
        ans += cycle - 1;
    }
    return ans;
}

int main()
{
    vector<int> arr1{2, 4, 5, 1, 3};
    cout << countMinSwaps << endl;
    return 0;
}