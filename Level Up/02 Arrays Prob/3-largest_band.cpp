#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int largestBand(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> s;
    for (auto x : arr)
    {
        s.insert(x);
    }

    int largest = 0;
    for (auto element : s)
    {
        int parent = element - 1;
        if (s.find(parent) == s.end())
        {
            int next = element + 1;
            int cnt = 1;
            while (s.find(next) != s.end())
            {
                cnt++;
                next++;
            }
            largest = max(largest, cnt);
        }
    }
    return largest;
}

int main()
{
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << largestBand(arr) << endl;
    return 0;
}