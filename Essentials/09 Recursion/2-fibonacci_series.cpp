#include <iostream>
using namespace std;

// Write a recursive function to compute nth Fibonacci number

int fibonacci_num(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int f1 = fibonacci_num(n - 1);
    int f2 = fibonacci_num(n - 2);
    return f1 + f2;
}

int main()
{
    int num;
    cin >> num;
    cout << fibonacci_num(num) << endl;
    return 0;
}