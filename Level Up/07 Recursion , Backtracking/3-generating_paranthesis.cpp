// lc pe hai

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void generateParanthesis(string s, int n, int open, int close, int index)
{
    if (index == 2 * n)
    {
        cout << s << endl;
        return;
    }

    if (open < n)
    {
        generateParanthesis(s + "(", n, open + 1, close, index + 1);
    }

    if (close < open)
    {
        generateParanthesis(s + ")", n, open, close + 1, index + 1);
    }
}

int main()
{
    string output;
    int n;
    cin >> n;
    generateParanthesis(output, n, 0, 0, 0);
    return 0;
}