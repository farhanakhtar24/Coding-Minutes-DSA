#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string simplifyPath(string path)
{
    istringstream iss(path);
    vector<string> tokens;
    string token;

    // 1. tokenistation and filtering
    while (getline(iss, token, '/'))
    {
        if (token == "." || token == "")
        {
            continue;
        }
        tokens.push_back(token);
    }

    for (string t : tokens)
    {
        cout << t << " ";
    }

    // 2.Handle ..
    vector<string> stack;

    return "";
}

int main()
{
    string path = "/a/./b/../../c/";
    simplifyPath(path);
    return 0;
}