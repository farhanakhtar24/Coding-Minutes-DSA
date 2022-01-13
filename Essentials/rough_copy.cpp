#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int decimalToBinary(int n)
{
    if (n == 0)
    {
        return (n % 2);
    }
    string temp = "";
    while (n > 0)
    {
        temp += to_string(decimalToBinary(n / 2));
    }
}

int main()
{
    int n;
    cin >> n;
    cout << decimalToBinary(n) << endl;
    return 0;
}