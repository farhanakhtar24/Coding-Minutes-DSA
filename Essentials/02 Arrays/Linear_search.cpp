/*
It's a brute force search algorithm
O(n) time complexity
*/

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        // Checks if current element matches the given key
        if (arr[i] == key)
        {
            return i;
        }
    }

    // If no element matches the key
    return -1;
}

int main()
{
    int arr[] = {13, 4, 54, 87, 8, 9, 7, 64, 13, 21, 6, 5, 46, 6};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cout << "Enter the key : ";
    cin >> key;

    int index = linearSearch(arr, n, key);
    if (index != -1)
    {
        cout << key << " is present at " << index << " index" << endl;
    }
    else
    {
        cout << key << " is not present in the array" << endl;
    }
    return 0;
}