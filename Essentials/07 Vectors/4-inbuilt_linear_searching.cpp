/*
Inbuilt function for doing linear search is find function
It is a part of a header file known as algorithm

arr.begin() stands for the base address or the address of first element of an array
arr.end() is an address which stand for the address of that chunk of memory which exist just after the last element
of the array

the find() function stores the address of the element , whenever it finds the key , but if it doesn't finds the element
then the iterator stores a the address of arr.end() which is just after the last element of the array
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {10, 10, 2, 11, 31, 2, 3, 4, 5, 6, 7};

    int key;
    cin >> key;
    vector<int>::iterator it = find(arr.begin(), arr.end(), key);

    if (it != arr.end())
    {
        cout << "Key is present at " << it - arr.begin() << " index" << endl; // to get the index of the iterator we have to
                                                                              // subtract array's base address from 'it'
    }
    else
    {
        cout << "Element not found " << endl;
    }
    return 0;
}