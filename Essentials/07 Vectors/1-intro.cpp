/*
Uptil now we have created arrays which have a fixed(leaving the dynamic arrays of heap)
The vectors allow us to make arrays of variable sizes , who's sizes can be altered.

The growing of vector size happens in such a way that if we want to an element to the array and the array is full then
the vector's size will get doubled of what it was before adding the element and then the element will be added in the 
doubled array
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Creating empty vector arr
    vector<int> arrempty;
    cout << arrempty.size() << endl;

    // Creating an initialised vector arr
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    // the pushback function adds the element at the end of the array in constant time
    arr.push_back(16);

    // the popback function removes the element at the end of the array in constant time
    arr.pop_back();

    // Printing array elements
    for (int x : arr)
    {
        cout << "Arr : " << x << endl;
    }

    cout << arr.size() << endl;     // .size() teel us the number of elements
    cout << arr.capacity() << endl; // capacity tells us what is the actual memory allocated to this vector array

    // Fill constructor
    vector<int> arrFilled(100, 0);
    for (int x : arrFilled)
    {
        cout << "ArrFilled : " << x << endl;
    }
    return 0;
}