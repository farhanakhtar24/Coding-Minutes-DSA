/*
This sort algo is provided in algorithm header file
The sort alogrithm works in TC of n(log(n)) time , which is much better than bubble,selection and insertion(O(n^2)).

The sorting function is a higher order function which takes can even take other functionsa as input just like 
addeventhandler method. 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {-2, 3, -12, 4, -1, 5, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    // Sorting function which works in nLogn time complexity
    sort(arr, arr + n);

    // Reverse funtion
    reverse(arr, arr + n);

    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}