#include <bits/stdc++.h>
using namespace std;

// this is a top down dp as it uses a recusrive case
int fiboncci(int n, int dp[])
{
    // cout << n << endl;
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    return dp[n] = fiboncci(n - 1, dp) + fiboncci(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    cout << fiboncci(n, dp) << endl;
    return 0;
}