#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// see logic video only

// string first_non_repeating_character(string str)
// {
//     unordered_map<char, int> mp;
//     queue<char> q;
//     string output;
//     for (auto ch : str)
//     {
//         q.push(ch);
//         mp[ch]++;
//         while (!q.empty())
//         {
//             if (mp[q.front()] > 1)
//             {
//                 q.pop();
//             }
//             else
//             {
//                 output.push_back(q.front());
//                 break;
//             }
//         }
//         if (q.empty())
//         {
//             output.push_back('0');
//         }
//     }
//     return output;
// }

string first_non_repeating_character(string str)
{
    queue<char> q;
    unordered_map<char, int> mp;

    string output;
    for (auto ch : str)
    {
        mp[ch]++;
        q.push(ch);

        while (!q.empty())
        {
            if (mp[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                output.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            output.push_back('0');
        }
    }
    return output;
}

int main()
{
    string str = "aaabbcdbbaac";
    cout << first_non_repeating_character(str) << endl;
    return 0;
}