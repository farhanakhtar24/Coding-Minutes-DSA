#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int iterations = 0; iterations < n - 1; iterations++)
    {
        for (int j = 0; j < n - iterations - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {-2, 3, -12, 4, -1, 5, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}