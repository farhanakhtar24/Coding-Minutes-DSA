// Determine if there is a subset whose sum is equal to the given sum and if yes then count many such subsets are there

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int countSubset(vector<int> arr, int n, int i, int x)
{
    // base case
    if (i == n)
    {
        if (x == 0)
        {
            return 1;
        }
        return 0;
    }

    int inc = countSubset(arr, n, i + 1, x - arr[i]);
    int exc = countSubset(arr, n, i + 1, x);

    return inc + exc;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    int n = arr.size();
    int x;
    cin >> x;
    cout << countSubset(arr, n, 0, x);
    return 0;
}