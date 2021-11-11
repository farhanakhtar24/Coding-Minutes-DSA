/*
The 2-d arrays are declared like a matrix with first variable pointing rows and second variable pointing columns
eg:- A[r][c];
We may assume the structure of the array as a square box ,but in reality the memory is allocated linearly,.i.e.
the memory is allocated as a single dimentional array.
*/
#include <iostream>
using namespace std;

int main()
{
    // 1st Method of crating 2-D array : Full array in stack

    // This array is created inside the stack as we did'nt use the new keyword.
    int A[3][4] = {
        {1, 2, 3, 11},
        {4, 5, 6, 10},
        {7, 8, 9, 12}}; // Declartion with initialisation

    // 2nd Method of crating 2-D array : Pointer array in stack, 1-D array in heap

    // Here in this pointers array we will use each element of this array and point to a 1-D array made in heap.
    // As the heap object can be made only with the help of pointers , we have used pointers here.
    // Here the pointers array is made in stack but , the 1-D arrays are made in heap

    int *Arrptr[3];
    Arrptr[0] = new int[4];
    Arrptr[1] = new int[4];
    Arrptr[2] = new int[4];
    // this array created is same as the array created above

    // 3rd Method of crating 2-D array : Full arrays in heap
    int **Arr;           // Here this Arr is a double pointer and this is variable created in stack
    Arr = new int *[3];  // this is the pointers arrays which earlier was created in stack , is not being directly made in heap
    Arr[0] = new int[4]; // this is same as above
    Arr[1] = new int[4];
    Arr[2] = new int[4];
    // this array created is same as the array created above

    // Accessing elements of the array made by all the 3 methods above are same
    A[1][2] = 0;
    Arrptr[1][2] = 0;
    Arr[1][2] = 0;

    return 0;
}