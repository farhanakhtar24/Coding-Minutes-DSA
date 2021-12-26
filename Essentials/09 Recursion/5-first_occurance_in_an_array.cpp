#include <iostream>
using namespace std;

int firstOccurance(int arr[], int size, int key)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[0] == key)
    {
        return 0;
    }
    int index = firstOccurance(arr + 1, size - 1, key);
    if (index != -1)
    {
        index++;
    }
    return index;
}

int main()
{
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(int);
    int key = 1;
    cout << "index : " << firstOccurance(arr, size, key) << endl;
    return 0;
}