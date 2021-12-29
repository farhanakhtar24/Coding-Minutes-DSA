#include <iostream>
using namespace std;

int lastOccForLoop(int arr[], int size, int key)
{
    int counter = -1;
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            counter = i;
        }
    }

    if (counter != -1)
    {
        return counter;
    }
    return -1;
}

int lastOccRecursion(int arr[], int size, int key)
{
    if (size == 0)
    {
        return -1;
    }

    int index = lastOccRecursion(arr + 1, size - 1, key);

    if (index == -1) // it means the key was not present inside the whole array
    {
        if (arr[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return index + 1;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 1, 2, 3, 5, 4, 5, 6, 4, 6, 5, 7, 8, 7, 8};
    int size = sizeof(arr) / sizeof(int);
    int key = 5;
    cout << "For loop : " << lastOccForLoop(arr, size, key) << endl;
    cout << "Using Recursion : " << lastOccRecursion(arr, size, key) << endl;
    return 0;
}