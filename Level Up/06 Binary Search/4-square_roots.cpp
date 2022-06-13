#include <iostream>
#include <bits/stdc++.h>

using namespace std;

float squareRoot(int N, int P)
{
    int s = 0;
    int e = N;
    float ans = 0;

    // binary search to get integer part
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (mid * mid == N)
        {
            return mid;
        }
        else if (mid * mid < N)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    // linear search
    float inc = 0.1;
    for (int place = 1; place <= P; place++)
    {
        while (ans * ans <= N)
        {
            ans += inc;
        }

        ans = ans - inc;
        inc = inc / 10.0;
    }
    return ans;
}

int main()
{
    int n, p;
    cin >> n >> p;

    cout << squareRoot(n, p) << endl;

    return 0;
}