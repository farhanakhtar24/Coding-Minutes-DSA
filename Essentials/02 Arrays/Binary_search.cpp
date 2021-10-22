/*
*/

#include <iostream>
using namespace std;

int Binary(int arr[], int size, int key)
{
    int s = 0, e = size - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return 2;
}

int main()
{
    int arr[] = {13, 4, 54, 87, 8, 9, 7, 64, 13, 21, 6, 5, 46, 6};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cout << "Enter the key : ";
    cin >> key;
    int index = Binary(arr, n, key);
    cout << index << endl;
    return 0;
}