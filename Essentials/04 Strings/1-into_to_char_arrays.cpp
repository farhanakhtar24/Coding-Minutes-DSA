/*
When we add double quotes over a string then the compiler already puts the null character at the end of the string
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    /*** CREATING CHAR ARRAY ***/
    char arr[100];

    char td[] = {'a', 'b', 'c', 'd', '\0'}; // we should always add null character at the end of this kind of initialisation

    char c[100] = "abc"; // This type of initialising already puts null character(\0) at the end of the string

    /*** INPUT OUTPUT ***/
    cout << td << endl;

    cout << strlen(td) << endl; // Number of visible characters
    cout << sizeof(td) << endl; // Number of real cahracter stroed in char array including null character

    return 0;
}