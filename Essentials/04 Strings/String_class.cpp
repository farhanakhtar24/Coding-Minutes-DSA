#include <iostream>
#include <string>

using namespace std;

int main()
{
    char cstr; // this is a fixed array

    string str; // This string is a dynamic array
    str = "hello world";
    cout << str << endl;

    string str2("Good morning"); // this is another method of initialising a string

    string str3;
    getline(cin, str3, '.'); // The third parameter specifies where the function has to stop taking input
    cout << str3 << endl;
    return 0;
}