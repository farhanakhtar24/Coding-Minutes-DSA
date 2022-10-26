#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int helper(int n, string goal, string targets)
{
    // cout << n << " " << goal << " " << targets;
    unordered_map<string, int> mp;
    string curr_String = "";
    for (auto x : targets)
    {
        if (x != ' ')
        {
            curr_String.push_back(x);
        }
        else
        {
            mp[curr_String]++;
            curr_String = "";
        }
    }

    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}

int main()
{
    int n;
    string goal, targets;
    cin >> n;
    cin >> goal;
    getline(cin, targets);
    cout << targets << endl;
    // int k = helper(n, goal, targets);
    return 0;
}