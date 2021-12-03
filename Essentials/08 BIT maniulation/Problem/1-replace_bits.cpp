#include <iostream>
using namespace std;

// Replace BITS in N by M
/*
You are given two 32-bit numbers , N and M. And two bit positions i and j .
Write a method to set between all bits i and j in N equal to M.
M (becomes a substring of N locationed at and staritng at j).

Example: 
N = 1000000000
M = 10101
i = 2 ,j = 6
Output = 1001010100

*/

void clearBitsInRange(int &num, int i, int j)
{
    int mask1 = (~0) << (j + 1);
    int mask2 = (1 << i) - 1;
    int mainMask = mask1 | mask2;
    num = num & mainMask;
}

void replaceBits(int &N, int M, int i, int j)
{
    clearBitsInRange(N, i, j);
    int mask = (M << i);
    N = N | mask;
}

int main()
{
    int N = 15, M = 2;
    int i = 1, j = 3;
    replaceBits(N, M, i, j);
    cout << N << endl;
    return 0;
}