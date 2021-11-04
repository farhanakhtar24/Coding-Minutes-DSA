#include <iostream>
#include <string>

using namespace std;

int main()
{
    char cstr; // this is a fixed array

    string str; // This string is a dynamic array
    str = "hello world";
    cout << str << endl;

    // INITIALISATION USNG CONSTRUCTOR FUNCTION
    string str2("Good morning"); // this is another method of initialising a string

    // GETLINE FUNCTION
    string str3;
    getline(cin, str3, '.'); // The third parameter specifies where the function has to stop taking input
    cout << str3 << endl;

    // ITRATING OVER EACH CHAR USING FOR LOOP
    for (char x : str)
    {
        cout << x << endl;
    }
    return 0;
}