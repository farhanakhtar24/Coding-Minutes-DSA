#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// print names n times
// TC :O(n) , SC :O(n)
void printNames(int n)
{
    if (n <= 0)
    {
        return;
    }
    cout << "Farhan" << endl;
    printNames(--n);
}

int main()
{
    printNames(5);
    return 0;
}