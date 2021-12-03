#include <iostream>
using namespace std;

/*
16 = 1000
15 = 16-1 = 0111

16 & 15 = 0

Unique property of two's power numbers
N & (N-1) = 0 , when N is a power of 2
*/

int main()
{
    int num;
    cin >> num;

    if ((num & (num - 1)) == 0)
    {
        cout << "Power of Two" << endl;
    }
    else
    {
        cout << "Not a power of Two" << endl;
    }

    return 0;
}