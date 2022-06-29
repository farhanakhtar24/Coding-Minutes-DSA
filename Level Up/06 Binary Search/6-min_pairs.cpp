// SAMAJH NAHI AAYA

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void minPairs(vector<int> &a1, vector<int> &a2)
{
    // sorting a2
    sort(a2.begin(), a2.end());

    int p1, p2;
    int diff = INT_MAX;

    // iterate over one array and look for closest elements in the second array
    for (auto x : a1)
    {
        auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin(); // lb is an index here

        // left
        if (lb >= 1 && x - a2[lb - 1] < diff)
        {
            diff = x - a2[lb - 1];
            p1 = x;
            p2 = a2[lb - 1];
        }

        // greater / right
        if (lb != a2.size() &&)
        {
        }
    }
}

int main()
{
    vector<int> a1{-1, 5, 10, 20, 3};
    vector<int> a2{26, 134, 135, 15, 17};
    minPairs(a1, a2);
    return 0;
}