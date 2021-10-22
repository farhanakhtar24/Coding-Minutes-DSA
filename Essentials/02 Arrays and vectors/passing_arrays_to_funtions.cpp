/*
The problem occuring here is because we are not apssing the whole array , instead we are passing the address of array 
inside a pointer and the pointer inside the printArray() function haves size as 8 bytes 
*/
#include <iostream>
using namespace std;

void printArray(int arr[])
{
    cout << "In Funtion size of arr is " << sizeof(arr) << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(int); // here arrSize = 24 bytes and int size is 4 bytes

    cout << "In Main size of arr is " << sizeof(arr) << endl;
    printArray(arr);
    // cout << sizeof(int) << endl;
    return 0;
}