#include <iostream>
using namespace std;

// PROBLEM : Reverse the array

void reverseArray(int arr[], int size)
{
    int s = 0, e = size - 1;
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++, e--;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr) / sizeof(int);

    cout << "Original Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    reverseArray(arr, n);

    cout << "Reversed Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}