#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void func(int cnt)
{
    if (cnt == 4)
    {
        return;
    }
    cout << cnt << endl;
    cnt++;
    func(cnt);
}

int main()
{
    // cout << Hello World' << endl;
    func(0);
    return 0;
}