#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void maxSubarray(vector<int> &arr, int k)
{
    deque<int> Q(k);
    int i = 0;
    // Process only the first k elements
    for (i = 0; i < k; i++)
    {
        while (!Q.empty() && arr[i] > Q.back())
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    // Remaining the elements of the array
    for (; i < arr.size(); i++)
    {
        cout << arr[Q.front()] << endl;
        // removing the element from left (contraction when an index lies outside the current window)
        while (!Q.empty() && Q.front() <= i - k)
        {
            Q.pop_front();
        }

        while (!Q.empty() && arr[i] >= arr[Q.back()])
        {
            Q.pop_back();
        }

        Q.push_back(i);
    }
}

int main()
{
    vector<int> arr{1, 2, 3, 1, 4, 5, 2, 3, 5};
    int window = 3;
    maxSubarray(arr, window);
    return 0;
}