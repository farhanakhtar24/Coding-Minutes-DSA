/*
Pointer is a variable which holds the address of another variable
To declare a pointer we use an asterisk between the dataType and the variable name

Pointer should be of same datatype as that of the variable it is pointing to
*/

#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    // Pointer to a variable
    int *xptr = &x;
    cout << "Address of x variable : " << &x << endl;
    cout << endl;
    cout << "Address stored in xptr : " << xptr << endl;
    cout << endl;
    cout << "Value of x variable xptr is pointing to : " << *xptr << endl;
    cout << endl;
    cout << "Address of xptr : " << &xptr << endl;
    cout << endl;

    // Pointer to a pointer variable(double pointer)
    int **xxptr = &xptr;
    cout << "Address stored in xptr : " << xxptr << endl;
    cout << endl;
    cout << "Address of x variable : " << **xxptr << endl;
    return 0;
}