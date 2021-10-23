#include <iostream>
using namespace std;

// PROBLEM : Print sum of each subarray and print out the largest sum

// Brute force approach
void sumOfSubArrays_BruteForce(int arr[], int n)
{
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int k = i;
            int sum = 0;
            // For each subarray sum if added in this while loop
            while (k <= j)
            {
                sum += arr[k];
                k++;
            }
            cout << sum << ",";

            // Calculating largest sum after each subarray iteration
            largest = max(largest, sum);
        }
        cout << endl;
    }
    cout << "Largest : " << largest << endl;
}

// Prefix Sum approach

/* 
Prefix sum array is an array which contains sum of each subarray till last element of subarray .
eg:         [ 1 ,2 ,4 ,-2 ,3 ]

            *****SUMS****
when i=1    1 ,3 ,7 ,5 ,8
when i=2       2 ,6 ,4 ,7
                  4 ,2 ,5
                    -2 ,1
                        3 


Alogritm to make prefix array:- 

 for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

TC : O(n^2)
*/

void sumOfSubArraysPrefixSum(int arr[], int n)
{
    // Prefix Sums
    int prefix[n] = {0}; // initialised all element as 0
    prefix[0] = arr[0];  // initialised first element as arr[0]

    // Making Prefix Array
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];

            // Calculating largest sum after each summing of subarrays using prefix method
            largest = max(largest, sum);
        }
    }

    cout << "Largest : " << largest << endl;
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    sumOfSubArrays_BruteForce(arr, n);
    sumOfSubArraysPrefixSum(arr, n);
    return 0;
}