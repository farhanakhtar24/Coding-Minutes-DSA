#include <iostream>
using namespace std;

// Write a recursive function to check if an array is sorted or not

bool sortedArrayChecker(int arr[], int size)
{
    // Base case
    if (size == 1 || size == 0)
    {
        return true;
    }
    // Recursive Case
    if (arr[0] < arr[1] && sortedArrayChecker(arr + 1, size - 1))
    {
        return true;
    }
    return false;
}

bool sortedArrayCheckerNew(int arr[], int i, int size)
{
    if (i == size - 1) // the case when the pointer reaches the last index
    {
        return true;
    }

    if (arr[i] < arr[i + 1] && sortedArrayCheckerNew(arr, i + 1, size))
    {
        return true;
    }

    return false;
}

int main()
{
    int array[] = {1, 24, 3, 5, 6};
    int size = sizeof(array) / sizeof(int);
    cout << sortedArrayChecker(array, size) << endl;
    cout << sortedArrayCheckerNew(array, 0, size);
    return 0;
}