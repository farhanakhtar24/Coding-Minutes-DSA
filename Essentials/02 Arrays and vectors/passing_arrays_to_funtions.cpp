/*
The problem occuring here is because we are not passing the whole array , instead we are passing the address of array 
inside a pointer and the pointer inside the printArray() function haves size as 8 bytes

Here we are passing the array as pass by reference and not by pass by value , so therefore the size which 
comes out in printArray() function is not of the array but of the pointer pointing towards array
Therfore it is advised to pass the size of array alongside the array to a function

Point to remember ==> When we pass the array to a fucntion then the arrays are being passed by reference and not by value  
*/
#include <iostream>
using namespace std;

void printArray(int arr[], int size) // here we can use either arr[] or *arr
{
    cout << "In Funtion size of arr is " << sizeof(arr) << endl;
    cout << endl;

    //Comformation
    arr[0] = 100;

    cout << "Array in function" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(int); // here arrSize = 24 bytes and int size is 4 bytes

    printArray(arr, size);

    cout << "In Main size of arr is " << sizeof(arr) << endl;
    cout << endl;

    cout << "Array in Main" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    /*
    Here we have changed the value of the first element inside the function and it can be seen that the value is changed
    inside the array of main function too.
    This does gives confirmation that both arrays share same memory 
    */

    return 0;
}