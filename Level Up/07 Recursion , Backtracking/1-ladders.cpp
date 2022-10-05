// At most we can take a jump of 1,2,3 --> its written in problem statement

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// TC : O(3^n)

int ways(int n)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0 || n == 1)
    {
        return 1;
    }

    return ways(n - 1) + ways(n - 2) + ways(n - 3);
}

int main()
{
    int n;
    cin >> n;
    cout << "Ans : " << ways(n);
    return 0;
}