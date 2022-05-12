#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void replaceSpace(char *str)
{
    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            spaces++;
        }
    }
    cout << spaces << endl;
    int totalSize = strlen(str) + (spaces * 2);
    str[totalSize] = '\0';
    totalSize--;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[totalSize--] = '0';
            str[totalSize--] = '2';
            str[totalSize--] = '%';
        }
        else
        {
            str[totalSize--] = str[i];
        }
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replaceSpace(input);
    cout << input;
    return 0;
}