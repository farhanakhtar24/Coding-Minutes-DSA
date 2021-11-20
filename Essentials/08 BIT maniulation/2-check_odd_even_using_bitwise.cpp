#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    if (num & 1 == 1) // we do '&' between the number and 1 as the last bit of 1 is 1 and the last bit is the deciding
                      // factor whether a number is even(last bit of number is 0) or odd(last bit of number is 1)
    {
        cout << "odd" << endl;
    }
    else
    {
        cout << "even" << endl;
    }
    return 0;
}