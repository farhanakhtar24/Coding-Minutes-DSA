#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool solveNQueen(int n, int board[][20], int i)
{
    if (i == n)
    {
        printBoard();
        return;
    }
}
int main()
{
    int board[20][20] = {0};
    int n;
    cin >> n;
    return 0;
}