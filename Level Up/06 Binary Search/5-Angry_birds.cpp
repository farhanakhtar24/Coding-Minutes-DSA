#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canPlaceBirds(int B, int N, vector<int> &nests, int mid)
{
    int birds = 1;
    int location = nests[0];
    for (int i = 1; i < N; i++)
    {
        int curr_location = nests[i];
        if (curr_location - location >= mid)
        {
            birds++;
            location = curr_location;
            if (birds == B)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int B = 3;

    vector<int> nests{1, 2, 4, 8, 9};
    // nests should be sorted even if they are not sorted

    int N = nests.size();

    // Binary Search
    int s = 0;
    int e = nests[N - 1] - nests[0]; // max distance that we can have
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool canPlace = canPlaceBirds(B, N, nests, mid);

        if (canPlace)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}