/*
This algo is only applicable when array is sorted rowise and columnwise both

The brute force TC of this problem is o(n*m)
But the optimized apporach makes it in linear TC with O(n+m)


Pair is an inbuilt structure that can store 2 entities. It is a kind of datatype just like int , char , float 
and nothing complex

*/

#include <iostream>
using namespace std;

pair<int, int> stairCase(int arr[][4], int r, int c, int key)
{
    // If the key element is not present then return {-1,-1}
    if (key < arr[0][0] || key > arr[r - 1][c - 1])
    {
        return {-1, -1};
    }

    // ALgorithm from here
    // Here we take the starting element as the element which is thelast element of first row
    int i = 0, j = c - 1;

    while (i < r && j >= 0) // the condition here means that the search should'nt excedd the bottom leftest element of the array
    {
        if (arr[i][j] == key)
        {
            return {i, j};
        }
        else if (arr[i][j] > key)
        {
            j--;
        }
        else if (arr[i][j] < key)
        {
            i++;
        }
    }
    return {-1, -1};
}

int main()
{
    int arr[][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };
    int n = 4, m = 4;

    pair<int, int> cords = stairCase(arr, n, m, 27);

    // the pair datatype has two attributes .i.e. first and second
    cout << cords.first << " " << cords.second << endl;

    return 0;
}