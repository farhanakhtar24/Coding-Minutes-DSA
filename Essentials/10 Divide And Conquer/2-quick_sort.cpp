/*
1.Choose a pivot point (point about which we are going to divide our array)
2.Partition
3.Recursive sort - quickSort

// Base Case
// 1 or 0 elements :return from that part

Partition :-
*/

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int, int e)
{
}

void quickSort(vector<int> &arr, int s, int e)
{
    // Base case
    if (s >= e)
    {
        return;
    }

    // Recursive Case
    int p = partition(arr, s, e);
}

int main()
{
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};

    int s = 0;
    int e = arr.size() - 1;

    quickSort(arr, s, e)

        for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}