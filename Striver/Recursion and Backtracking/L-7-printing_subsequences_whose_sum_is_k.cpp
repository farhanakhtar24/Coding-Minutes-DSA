#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool printS(vector<int> &arr, vector<int> &ans, int sum, int s, int i)
{
    if (i == arr.size())
    {
        if (s == sum)
        {
            for (auto x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    ans.push_back(arr[i]);
    s += arr[i];
    if (printS(arr, ans, sum, s, i + 1))
    {
        return true;
    }
    ans.pop_back();
    s -= arr[i];
    if (printS(arr, ans, sum, s, i + 1))
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int> arr{1, 2, 1};
    int sum = 2;
    vector<int> ans;
    int s = 0;
    printS(arr, ans, sum, s, 0);
    return 0;
}