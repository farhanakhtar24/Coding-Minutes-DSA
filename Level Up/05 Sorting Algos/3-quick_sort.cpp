#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int s, int e)
{
    int pivot = a[e];
    int i = s - 1;

    for (int j = s; j < e; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quickSort(vector<int> &a, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}

int main()
{

    vector<int> v{10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = v.size() - 1;
    quickSort(v, s, e);

    for (auto x : v)
    {
        cout << x << endl;
    }
    return 0;
}