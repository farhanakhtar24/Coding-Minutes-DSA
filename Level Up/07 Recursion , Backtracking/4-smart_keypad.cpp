// Find all the possible strings generated from the number of keypad

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string keys[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void keypad(string input, string output, int i)
{
    if (input[i] == '\0')
    {
        cout << output << endl;
        return;
    }

    int current_digit = input[i] - '0';
    if (current_digit == 0 || current_digit == 1)
    {
        keypad(input, output, i + 1);
    }

    for (int k = 0; k < keys[current_digit].size(); k++)
    {
        keypad(input, output + keys[current_digit][k], i + 1);
    }
}

int main()
{
    int n;
    cin >> n;

    string output;

    keypad(to_string(n), output, 0);

    return 0;
}