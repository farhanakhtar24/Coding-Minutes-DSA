#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t)
{
    int FP[256] = {0};
    int FS[256] = {0};

    for (int i = 0; i < t.length(); i++)
    {
        FP[t[i]]++;
    }

    // Sliding window algo
    int cnt = 0;
    int start = 0; // left contraction
    int start_idx = -1;
    int min_so_far = INT_MAX;
    int window_size;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // expand the window
        FS[ch]++;

        // expansion
        // count how many characters have been matched
        if (FP[ch] != 0 && FS[ch] <= FP[ch])
        {
            cnt += 1;
        }

        // contraction
        if (cnt == t.length())
        {
            while (FP[s[start]] == 0 || FS[s[start]] > FP[s[start]])
            {
                FS[s[start]]--;
                start++;
            }
            window_size = i - start + 1;
            if (window_size < min_so_far)
            {
                min_so_far = window_size;
                start_idx = start;
            }
        }
    }
    if (start_idx == -1)
    {
        return "No window found";
    }
    return s.substr(start_idx, min_so_far);
}

int main()
{
    string s, n;
    cin >> s >> n;
    cout << minWindow(s, n) << endl;
    return 0;
}