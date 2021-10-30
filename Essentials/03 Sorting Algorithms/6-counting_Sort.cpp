/*
This sorting algo almost works in linear time complexity
*/
#include <iostream>
using namespace std;

void countingSort(int arr[], int n)
{
    // Finding larget element
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
}

int main()
{
    int arr[] = {-2, 3, -12, 4, -1, 5, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    countingSort(arr, n);

    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}