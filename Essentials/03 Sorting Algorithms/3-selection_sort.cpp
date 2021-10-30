#include <iostream>
using namespace std;

void SelectionSortAlgo(int arr[], int n)
{
    for (int minimum = 0; minimum < n - 1; minimum++)
    {
        for (int j = minimum + 1; j < n; j++)
        {
            if (arr[minimum] > arr[j])
            {
                swap(arr[j], arr[minimum]);
            }
        }
    }
}

int main()
{
    int arr[] = {-2, 3, -12, 4, -1, 5, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    SelectionSortAlgo(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}