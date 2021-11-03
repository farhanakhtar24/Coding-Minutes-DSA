#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[1000] = "apple";
    char b[1000];

    // Calc Length
    cout << strlen(a) << endl;

    // StrCopy
    strcpy(b, a);
    cout << b << endl;

    char c[] = "sexyJutsu";

    // Compare
    cout << strcmp(c, b) << endl;
    return 0;
}