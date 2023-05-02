#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int pivot = e;
    e--;
    while (s <= e)
    {
        if (arr[s] > arr[pivot])
        {
            swap(arr[s], arr[e]);
            e--;
        }
        else
        {
            s++;
        }
    }
    swap(arr[s], arr[pivot]);
    return s;
}

void quickSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int partitionIndex = partition(arr, s, e);
    quickSort(arr, s, partitionIndex - 1);
    quickSort(arr, partitionIndex, e);
}

int main()
{
    vector<int> arr{1, 7, 3, 8, 4, 6, 8, 2, 0, 2, 560};
    quickSort(arr, 0, arr.size() - 1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}