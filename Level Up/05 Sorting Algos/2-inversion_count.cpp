#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &v, int s, int e)
{
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;

    vector<int> temp;
    int cnt = 0;
    while (i <= mid && j <= e)
    {
        if (v[i] < v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            cnt += mid - i + 1;
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
        // k++;
    }
    return cnt;
}

int inversionCount(vector<int> &v, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    int C1 = inversionCount(v, s, mid);
    int C2 = inversionCount(v, mid + 1, e);
    int CI = merge(v, s, e);
    return C1 + C2 + CI;
}

int main()
{
    vector<int> v{0, 5, 2, 3, 1};
    int s = 0;
    int e = v.size() - 1;
    cout << inversionCount(v, s, e) << endl;
    return 0;
}