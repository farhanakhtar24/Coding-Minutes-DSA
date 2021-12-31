#include <iostream>
#include <vector>
using namespace std;

/*
The D&C algorithm works on 3 simple steps:
1.Divide the array into 2 parts from mid point
2.Mergesort (left) and Mergesort(right)
3.Merge the left and right array using two pointer to fill in a temporary array and then copy the sorted array elements from
  the temporary array to original array
*/

void mergeArr(vector<int> &arr, int s, int e)
{
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;

    vector<int> temp;

    // this loop will go on until one the sorted array are exhausted . When this happens , then we will just have to copy
    // the remaining elements of the other sorted array at the end of the temp array
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements: Either one of these loops will be executed here.
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back elements from temp array to original array
    for (int index = s, k = 0; index <= e; index++, k++)
    {
        arr[index] = temp[k];
    }
    return;
}

// Sorting method
void mergeSortArr(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // recursive case
    int mid = (s + e) / 2;
    mergeSortArr(arr, s, mid);
    mergeSortArr(arr, mid + 1, e);
    return mergeArr(arr, s, e);
}

int main()
{
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};

    int s = 0;
    int e = arr.size() - 1;
    mergeSortArr(arr, s, e);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}