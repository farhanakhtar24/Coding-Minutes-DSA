#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    char *token = strtok(input, " ");

    while (token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, " ");
    }

    return 0;
}