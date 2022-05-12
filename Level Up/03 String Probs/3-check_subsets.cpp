#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool subsetChecker(string str, string subStr)
{
    int i = str.length() - 1;
    int j = subStr.length() - 1;
    while (i >= 0 && j >= 0)
    {
        if (str[i] == str[j])
        {
            i--;
            j--;
        }
        else
        {
            i--;
        }
    }
    if (j == -1)
    {
        return true;
    }
    return false;
}

int main()
{
    string str, subStr;
    cin >> str >> subStr;
    cout << subsetChecker(str, subStr) << endl;
    return 0;
}