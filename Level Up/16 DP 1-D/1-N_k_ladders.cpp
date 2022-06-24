#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// TC : O(k^n)
int ways(int N, int K)
{
    if (N == 0)
    {
        return 1;
    }

    if (N < 0)
    {
        return 0;
    }

    int ans = 0;
    for (int jump = 1; jump <= K; jump++)
    {
        ans += ways(N - jump, K);
    }

    return ans;
}

// Top Down Apporach
// TC : O(nk)
int waysTD(int N, int K, int dp[])
{
    if (N == 0)
    {
        return 1;
    }

    if (N < 0)
    {
        return 0;
    }

    if (dp[N] != 0)
    {
        return dp[N];
    }

    int ans = 0;
    for (int jump = 1; jump <= K; jump++)
    {
        ans += waysTD(N - jump, K, dp);
    }

    return dp[N] = ans;
}

// Bottom Up Approach
int waysBU(int N, int K)
{
    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[N];
}

int main()
{
    int N = 4;
    int K = 3;

    int dp[1000] = {0};
    cout << ways(N, K) << endl;
    cout << waysTD(N, K, dp) << endl;
    cout << waysBU(N, K) << endl;

    return 0;
}