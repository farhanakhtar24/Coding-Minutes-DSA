#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Sum of first N numbers
int sum(int n, int N)
{
    if (n > N)
    {
        return 0;
    }
    return n + sum(n + 1, N);
}

int main()
{
    cout << sum(1, 100) << endl;
    return 0;
}