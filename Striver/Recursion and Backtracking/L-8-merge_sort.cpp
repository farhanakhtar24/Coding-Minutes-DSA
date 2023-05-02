#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;

    vector<int> temp;
    while (i <= mid && j <= e)
    {
        if (arr[i] >= arr[j])
        {
            temp.push_back(arr[j]);
            j++;
        }
        else
        {
            temp.push_back(arr[i]);
            i++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;
    for (int i = s; i <= e; i++, k++)
    {
        arr[i] = temp[k];
    }
    return;
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
    return;
}

int main()
{
    vector<int> arr{1, 5, 7, 9, 1, 3, 5, 4, 6, 2};
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    mergeSort(arr, 0, arr.size() - 1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}