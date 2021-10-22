/*
A collection of elements of same type palced in a contiguos memory locations

Static memory allocation means that we are allocating the memory by our hands before execution.
eg: arr[5];

Dynamic means that we have provided a variable for memory allocation and during excution we gave that variable a value 
and now that value is allocated in memory
eg: x=5;
    arr[x];
*/
#include <iostream>
using namespace std;

int main()
{
    int a[100];       // allocate memory of 400 bytes
    int b[100] = {0}; // Now all elements are initialised as zero . Before this statements the values that would be stored
                      // wouldve been garbage values

    int c[100] = {1, 2, 3};    // the first 3 values wouldve been initialised , rest all would be initialised to 0.
    int d[] = {1, 2, 3};       // here the size will specified on the basis of elements initialised
    cout << sizeof(d) << endl; // Size =12 bytes .i.e. 3 elements

    string fruits[4] = {"Apple", "Doctor", "Away"};
    return 0;
}