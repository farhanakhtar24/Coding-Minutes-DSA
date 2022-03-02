#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n == 1 || n == 0)
        return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int N = 0;

    for (int i = 1; N != 100; i++)
    {
        if (i == 5 || i == 7)
        {
            continue;
        }
        if (isPrime(i))
        {
            cout << i << " ";
            N++;
        }
    }

    return 0;
}