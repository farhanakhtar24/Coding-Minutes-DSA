/*
How the arrays stored inside the memory?
==> In memory everything must be linearised. So the 2 methods of stroing the arrays are Row,Column major

Time taken by the compiler to store arrays in both methods is same.

*/

#include <iostream>
using namespace std;

// We always need to pass in the number of coloumns while initialising a 2d array or passing a 2d array to the function
void print(int arr[][100], int r, int c)
{
    // Taking output
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[100][100];
    int r, c;
    cin >> r >> c;

    // Taking input
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    print(arr, r, c);
    return 0;
}