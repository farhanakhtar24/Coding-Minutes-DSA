#include <iostream>
using namespace std;

// Prefix Sum Approach
void SumPrefixApproach(int arr[], int n)
{
    int largest = INT_MIN;
    int prefix[n] = {0};
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sumEachSubArray;
            // If i=0 then every subarray is starting from element 0
            sumEachSubArray = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];

            largest = max(sumEachSubArray, largest);
        }
    }
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    SumPrefixApproach(arr, n);
    return 0;
}