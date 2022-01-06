#include <iostream>
using namespace std;

void findTriplets(int arr[], int n)
{
    for (int i = 2; i < n; i++)
    {
        int findVar = arr[i - 2] + arr[i - 1];
        for (int j = i; j < n; j++)
        {
            if (findVar + arr[j] == 0)
            {
                cout << arr[i - 2] << " " << arr[i - 1] << " " << arr[j] << endl;
            }
        }
    }
}

int main()
{

    int arr[] = {0, -1, 2, -3, 1};
    int size = sizeof(arr) / sizeof(int);
    findTriplets(arr, size);
    return 0;
}