#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// reverse an array using a single pointer and recursion
void reverse(int i, int n, vector<int> &arr)
{
    if (i >= (n) / 2)
    {
        return;
    }

    swap(arr[i], arr[n - i - 1]);
    reverse(i + 1, n, arr);
}

int main()
{
    vector<int> arr{0, 1, 2, 3, 4};
    reverse(0, arr.size(), arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    // cout << 'Hello World' << endl;
    return 0;
}