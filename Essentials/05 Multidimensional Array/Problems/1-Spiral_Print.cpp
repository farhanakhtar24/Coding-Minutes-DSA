#include <iostream>
using namespace std;

int main()
{
    int arr[6][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {20, 21, 22, 23},
    };

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int row = 6, column = 4;

    // int startRow = 0;
    // int endRow = row - 1;
    // int startColoumn = 0;
    // int endColoumn = column - 1;

    // int counter = sizeof(arr) / sizeof(int);

    // while (counter > 0)
    // {
    //     // Start Row
    //     for (int col = startColoumn; col <= endColoumn; col++)
    //     {
    //         if (counter <= 0)
    //         {
    //             return 0;
    //         }
    //         cout << arr[startRow][col] << " ";
    //         counter--;
    //     }
    //     startRow++;
    //     // Last Column
    //     for (int row = startRow; row <= endRow; row++)
    //     {
    //         if (counter <= 0)
    //         {
    //             return 0;
    //         }
    //         cout << arr[row][endColoumn] << " ";
    //         counter--;
    //     }
    //     endColoumn--;
    //     //  Last Row
    //     for (int col = endColoumn; col >= startColoumn; col--)
    //     {
    //         if (counter <= 0)
    //         {
    //             return 0;
    //         }
    //         cout << arr[endRow][col] << " ";
    //         counter--;
    //     }
    //     endRow--;
    //     // First column
    //     for (int row = endRow; row >= startRow; row--)
    //     {
    //         if (counter <= 0)
    //         {
    //             return 0;
    //         }
    //         cout << arr[row][startColoumn] << " ";
    //         counter--;
    //     }
    //     startColoumn++;
    //     // for (j; j != 0; j--)
    //     // {
    //     //     cout << arr[i][j] << " ";
    //     // }
    // }

    int startrow = 0, endrow = row - 1;
    int startColumn = 0, endColumn = column - 1;

    int counter = sizeof(arr) / sizeof(int);

    while (counter > 0)
    {
        // StartRow
        for (int col = startColumn; col <= endColumn; col++)
        {
            if (counter <= 0)
            {
                return 0;
            }
            cout << arr[startrow][col] << " ";
            counter--;
        }
        startrow++;

        // Last column
        for (int row = startrow; row <= endrow; row++)
        {
            if (counter <= 0)
            {
                return 0;
            }
            cout << arr[row][endColumn] << " ";
            counter--;
        }
        endColumn--;

        // Last Row
        for (int col = endColumn; col >= startColumn; col--)
        {
            if (counter <= 0)
            {
                return 0;
            }
            cout << arr[endrow][col] << " ";
            counter--;
        }
        endrow--;

        //First column
        for (int row = endrow; row >= startrow; row--)
        {
            if (counter <= 0)
            {
                return 0;
            }
            cout << arr[row][startColumn] << " ";
            counter--;
        }
        startColumn++;
    }

    return 0;
}