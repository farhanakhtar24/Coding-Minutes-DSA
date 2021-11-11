/*
*/
#include <iostream>
using namespace std;

int **arrayMaker(int rows, int cols)
{
    int **arrPtr = new int *[rows]; // here the double pointer stores the address of the pointer array and this array of pointers stores the pointers which point to the arrays made in heap
    for (int i = 0; i < cols; i++)
    {
        arrPtr[i] = new int[cols];
    }
    return arrPtr;
}

int main()
{
    // making 2D dynamic array whole_ly inside heap
    int rows, columns;
    cin >> rows >> columns;
    int **arr = arrayMaker(rows, columns);
    return 0;
}