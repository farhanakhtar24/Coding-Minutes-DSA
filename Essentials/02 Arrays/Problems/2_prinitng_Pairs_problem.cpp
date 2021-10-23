#include <iostream>
using namespace std;

// PROBLEM : Print pairs of each element in the array

void printAllPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            cout << arr[i] << "," << arr[j] << endl;
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(int);
    printAllPairs(arr, n);
    return 0;
}