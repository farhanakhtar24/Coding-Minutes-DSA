#include <iostream>
using namespace std;

// Covert a number into the strings using recursion
// Digits are in range 0-9

string spell[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printer(int n)
{
    if (n == 0)
    {
        return;
    }

    int last_digit = n % 10;
    printer(n / 10);
    cout << spell[last_digit] << " ";
}

int main()
{
    int n;
    cin >> n;
    printer(n);
    return 0;
}