/*
the comaprators are nothing but blocks of code which has a logic ,which tells the sorting algorithm,
in which direction they should compare the elements.

The comparators are passed to the sorting function as the third parameter

Therefore to reverse an array we can either use sort() function with comparators or reverse() function as it is.
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool comaparators(int a, int b)
{
    return a > b;
}

int main()
{
    int arr[] = {-2, 3, -12, 4, -1, 5, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    // Sorting function which works in nLogn time complexity
    sort(arr, arr + n, comaparators);

    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}