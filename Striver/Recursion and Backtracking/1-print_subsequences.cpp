// Print all subsequnces following the order of the array
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        const int cnt = 9;
        bool cols[cnt][cnt] = {false};
        bool rows[cnt][cnt] = {false};
        bool sq[cnt][cnt] = {false};

        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < cnt; i++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int digit = board[i][j] - '0' - 1;
                int area = (i / 3) * 3 + j / 3;

                if (rows[i][digit] || cols[j][digit] || sq[area][digit])
                {
                    return false;
                }

                rows[i][digit] = true;
                cols[j][digit] = true;
                sq[area][digit] = true;
            }
        }

        return true;
    }
};