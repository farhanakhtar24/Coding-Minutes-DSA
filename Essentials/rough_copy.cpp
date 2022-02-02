#include <iostream>
#include <vector>
using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int j = 0;
    int Lsum = 0;
    for (int i = 0; i < accounts.size(); i++)
    {
        int Csum = 0;
        while (j < accounts[i].size())
        {
            Csum += accounts[i][j];
            j++;
        }
        if (Csum > Lsum)
        {
            Lsum = Csum;
        }
    }
    return Lsum;
}

int main()
{
    int row, col;
    vector<vector<int>> account;
    for (int i = 0)
        cout << maximumWealth(account) << endl;
    return 0;
}