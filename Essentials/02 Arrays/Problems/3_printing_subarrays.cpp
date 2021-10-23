/*
Subarrays are like smaller parts of main array
We can our knowledge from pairPrinting problem and iterate over each element in range over i-j to print subarrays

*/

#include <iostream>
using namespace std;

void printSubArrays(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // cout << "(" << i << "," << j << ") , ";
            cout << "(";
            int k = i;
            while (k <= j)
            {
                cout << arr[k] << ",";
                k++;
            }
            cout << ")" << endl;
        }
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(int);
    printSubArrays(arr, n);
    return 0;
}

// TC : O(n^3);