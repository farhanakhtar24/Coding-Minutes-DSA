#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> &arr, int key)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid;

    int ans = -1;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            ans = mid;

            // searching in left part of array to find the upper bound
            e = mid - 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int key)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid;

    int ans = -1;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            ans = mid;

            // searching in right part of array to find the upper bound
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{0, 1, 2, 2, 3, 3, 3, 3, 3, 4, 5, 5, 5, 10};
    int n = arr.size();

    cout << "Custom function -->" << endl;
    cout << "Frequency of element 3 : " << upperBound(arr, 3) - lowerBound(arr, 3) + 1 << endl;

    /****** STL for upper and lower bounds ******/
    cout << "STL method -->" << endl;
    cout << "Frequency of element 3 : " << upper_bound(arr.begin(), arr.end(), 3) - lower_bound(arr.begin(), arr.end(), 3) << endl;

    return 0;
}