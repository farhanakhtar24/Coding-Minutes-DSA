#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// subsequence : a contiguos/ non-continguos sequence , which follows the order
void subsequences(vector<int> &arr, vector<int> &ans, int i)
{
    if (i >= arr.size())
    {
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    subsequences(arr, ans, i + 1);
    ans.push_back(arr[i]);
    subsequences(arr, ans, i + 1);
    ans.pop_back();
    return;
}

int main()
{
    vector<int> arr{3, 1, 2};
    vector<int> ans;
    subsequences(arr, ans, 0);
    return 0;
}