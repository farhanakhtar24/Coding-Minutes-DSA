/*
In char arrays printing the address of a single element ,prints out the entire array .This behaviour in char arrays
is different with respect to int arrays. As in case of int arrays printing out the address of an array prints the 
address only and not the entire array

This difference in behavior comes out due to conditional statements written inside 'cout' keyword , which treats char
arrays differently than any other arrays 
*/

#include <iostream>
using namespace std;

int main()
{
    // Here 10 is the maximum number of coloumns/alpahabets that can be stored in each row of the array
    // We always need to pass in the number of coloumns while initialising a 2d array
    char numbers[][10] = {"one",
                          "two",
                          "three",
                          "four",
                          "five",
                          "six"};

    cout << numbers[2] << endl; // Here complete char array row is being printed

    char str[] = "Hello world";
    cout << str << endl; // Here complete char array is being printed

    int arr[] = {1, 2, 3, 4, 4};
    cout << arr << endl; // Here only address of the array is being printed
    return 0;
}