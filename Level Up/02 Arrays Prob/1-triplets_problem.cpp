#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> triplets(vector<int> &arr, int target)
{
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());
    int n = arr.size();

    // pich every a[i] ,pair sum for remaining part
    for (int i = 0; i <= n - 3; i++)
    {
        int j = i + 1;
        int k = n - 1;
        // using 2 pointers
        while (j < k)
        {
            int currentSum = arr[i];
            currentSum += arr[j];
            currentSum += arr[k];
            if (currentSum == target)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (currentSum > target)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    auto result = triplets(arr, 18);
    for (auto x : result)
    {
        for (auto j : x)
        {
            cout << j << " ,";
        }
        cout << endl;
    }
    return 0;
}