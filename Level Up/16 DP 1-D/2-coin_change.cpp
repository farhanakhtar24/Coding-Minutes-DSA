#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Top Down Approach
// int minCoinChangeTD(int n, vector<int> &coins, vector<int> &dp)
// {
//     if (n == 0)
//     {
//         return 0;
//     }

//     if (dp[n] != INT_MAX)
//     {
//         return dp[n];
//     }

//     for (auto x : coins)
//     {
//         if (n - x >= 0)
//         {
//             dp[n] = min(dp[n], minCoinChangeTD(n - x, coins, dp) + 1);
//         }
//     }

//     return dp[n] == INT_MAX + 1 : -1 ? dp[n];
// }

// Bottom Up Approach
int minCoinChangeBU(int n, vector<int> &coins)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for (int x : coins)
        {
            if (i - x >= 0 && dp[i - x] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
}

int main()
{
    vector<int> coins = {1, 5, 7, 10};
    int money;
    cin >> money;
    vector<int> dp(money + 1, INT_MAX);
    cout << minCoinChangeBU(money, coins) << endl;
    // cout << minCoinChangeTD(money, coins, dp) << endl;

    return 0;
}