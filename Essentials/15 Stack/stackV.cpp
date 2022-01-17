#include <iostream>
#include "stackV.h"

using namespace std;

int main()
{
    Stack<char> str;
    str.push('F');
    str.push('A');
    str.push('R');
    str.push('H');
    str.push('A');
    str.push('N');

    while (!str.empty())
    {
        cout << str.top() << " ";
        str.pop();
    }

    return 0;
}