#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool divideAmongK(int arr[], int n, int k, int min)
{
    int partitions = 0;
    int curr_friend = 0;

    for (int i = 0; i < n; i++)
    {
        if (curr_friend + arr[i] >= min)
        {
            partitions++;
            curr_friend = 0;
        }
        else
        {
            curr_friend += arr[i];
        }
    }

    return partitions >= k;
}

int k_partitons(int a[], int n, int k)
{
    int s = 0;
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        e += a[i];
    }

    int ans;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool isPossible = divideAmongK(a, n, k, mid);

        if (isPossible)
        {
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int a[] = {10, 22, 40, 50};
    int n = sizeof(a) / sizeof(int);
    int num_of_partitions = 3;

    cout << k_partitons(a, n, num_of_partitions) << endl;

    return 0;
}