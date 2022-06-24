#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int frogJumpTD(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int left = frogJumpTD(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;

    if (index > 1)
    {
        right = frogJumpTD(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
    }

    return dp[index] = min(left, right);
}

int frogJmupBU(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int firstStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int secondStep = INT_MAX;

        if (i > 1)
        {
            secondStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        dp[i] = min(firstStep, secondStep);
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    vector<int> height{30, 10, 60, 10, 60, 50};
    cout << frogJumpTD(n, height, dp) << endl;
    cout << frogJmupBU(n, height) << endl;
    return 0;
}