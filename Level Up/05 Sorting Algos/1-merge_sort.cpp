#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int s, int e)
{
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;

    vector<int> temp;
    while (i <= mid && j <= e)
    {
        if (v[i] < v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while (j <= e)
    {
        temp.push_back(v[j]);
        j++;
    }

    int k = 0;
    for (int i = s; i <= e; i++)
    {
        v[i] = temp[k++];
    }
    return;
}

void inversionCount(vector<int> &v, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    inversionCount(v, s, mid);
    inversionCount(v, mid + 1, e);
    merge(v, s, e);
    return;
}
int main()
{
    vector<int> v{10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = v.size() - 1;
    inversionCount(v, s, e);
    for (auto x : v)
    {
        cout << x << endl;
    }
    return 0;
}