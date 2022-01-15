/*
A stack is a container in which we can :
1. Push more data from the top { O(1) }
2. Pop some data from the top { O(1) }
3. Also see what is present at the top { O(1) }
*/

#include <iostream>
#include "stackLL.h"

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

    while (!str.isEmpty())
    {
        cout << str.top() << " ";
        str.pop();
    }

    return 0;
}