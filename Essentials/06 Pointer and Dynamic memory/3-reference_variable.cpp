#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int &y = x;
    // Now both x and y both point to same memory which eas earlier alloacted for x variable.
    // This means that both x and y refers to the same variable

    x++;
    y++;
    cout << y << endl;
    return 0;
}