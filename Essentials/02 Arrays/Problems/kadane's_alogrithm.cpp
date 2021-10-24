/*
TC: O(n)
*/

#include <iostream>
using namespace std;

int Kadane_algorithm(int arr[], int n)
{
    int cs = 0, ms = 0;
    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        if (cs < 0)
        {
            cs = 0;
        }
        ms = max(cs, ms);
    }
    return ms;
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    cout << Kadane_algorithm(arr, n);
    return 0;
}