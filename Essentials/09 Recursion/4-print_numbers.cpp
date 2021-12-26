#include <iostream>
using namespace std;

// Print numbers from 1 to n recursively in

// 1.In Increasing order
void printInc(int n)
{
    if (n > 0)
    {
        printInc(n - 1);
        cout << n << " ";
    }
}

// 2.In Decreasing order
void printDec(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        printDec(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    printInc(n);
    cout << endl;
    printDec(n);

    return 0;
}