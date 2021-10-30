#include <iostream>
using namespace std;

void InsertionSortAlgo(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int currentElement = arr[i];
        int previousElement = i - 1;

        // Loop to find the right index where the current element should be inserted
        while (previousElement >= 0 && arr[previousElement] > currentElement)
        {
            arr[previousElement + 1] = arr[previousElement];
            previousElement--;
        }
        arr[previousElement + 1] = currentElement;
    }
}

int main()
{
    int arr[] = {-2, 3, -12, 4, -1, 5, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    InsertionSortAlgo(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}