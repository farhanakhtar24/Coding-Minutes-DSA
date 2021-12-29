#include <iostream>
using namespace std;

// Number and power is given as input

// TC : O(n)
int powerfunc(int num, int power)
{
    if (power == 0) // this means num^0
    {
        return 1;
    }
    num = num * powerfunc(num, power - 1);
    return num;
}

// TC : log(n)
// Space complexity : log(n)
int optimisedPowerFunc(int num, int power)
{
    if (power == 0)
    {
        return 1;
    }

    int ans = optimisedPowerFunc(num, power / 2);
    int ansSq = ans * ans;
    if (power & 1)
    {
        return (num * (ansSq));
    }
    return ansSq;
}

int main()
{
    int num, power;
    cout << "Enter number and power with a space in between : ";
    cin >> num >> power;

    cout << powerfunc(num, power) << endl;
    cout << optimisedPowerFunc(num, power) << endl;

    return 0;
}