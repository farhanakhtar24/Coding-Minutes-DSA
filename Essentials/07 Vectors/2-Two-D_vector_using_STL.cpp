/*
The vector 2d array is more powerful than the static 2d array as in this array, each row can have different number of 
elements
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3},     // 3 elements
        {4, 5, 6},     // 3 elements
        {7, 8, 9, 10}, // 4 elements
        {11, 12, 13},  // 3 elements
    };

    arr[2][3] = 100; // accessing an element is same as that in static 2d array

    for (int i = 0; i < arr.size(); i++)
    {
        for (int number : arr[i])
        {
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}