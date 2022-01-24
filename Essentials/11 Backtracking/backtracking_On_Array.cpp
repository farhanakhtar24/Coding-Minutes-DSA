#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    return;
}

void fillArray(int *arr, int i, int n, int val)
{
    //base case
    if (i == n)
    {
        //print our array
        printArray(arr, n);
        return;
    }

    //recursive case
    arr[i] = val;
    fillArray(arr, i + 1, n, val + 1);

    // backtracking step
    arr[i] = (-1) * arr[i];
}

int main()
{
    int arr[100] = {0};
    int n;
    cin >> n;
    fillArray(arr, 0, n, 1);
    cout << endl;
    printArray(arr, n);

    return 0;
}