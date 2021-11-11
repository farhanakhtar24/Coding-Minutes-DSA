/*
Pointer variable are supposed to hold the base address of the array created isnide heap .
So without the help of pointer we can't make any variable inside heap or iterate through the array made inside heap    
*/
#include <iostream>
using namespace std;

int main()
{
    int *income = new int[5]; // initialisation of dynamic array
    for (int i = 0; i < 5; i++)
    {
        cin >> income[i];
    }
    delete[] income; // deleting array
    return 0;
}