#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void housing(int arr[], int n, int k)
{
    int j = 0, i = 0;
    int cs = 0;
    while (j < n)
    {
        cs += arr[j];
        j++;
        while (cs > k)
        {
            cs = cs - arr[i];
            i++;
        }
        if (cs == k)
        {
            cout << i << " " << j - 1 << endl;
        }
    }
    return;
}

int main()
{
    int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(plots) / sizeof(int);
    int k;
    cin >> k;
    housing(plots, n, k);
    return 0;
}