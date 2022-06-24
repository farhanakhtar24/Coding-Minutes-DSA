#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int recurMax(int prices[], int n)
{
    // base case
    if (n <= 0)
    {
        return 0;
    }

    // rec case
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;
        int curAns = prices[i] + recurMax(prices, n - cut);
        ans = max(curAns, ans);
    }

    return ans;
}

int maxProfirDp(int prices[], int n, int dp[])
{
    // base case
    if (n <= 0)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;
        int curAns = prices[i] + maxProfirDp(prices, n - cut, dp);
        dp[n] = max(curAns, dp[n]);
    }

    return dp[n];
}

int maxProfitDpBU(int price[], int n)
{
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int ans = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            int cut = ;
        }
    }
}

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int dp[1000] = {0};
    int n = sizeof(prices) / sizeof(int);
    // cout << recurMax(prices, n) << endl;
    cout << maxProfirDp(prices, n, dp) << endl;
    return 0;
}