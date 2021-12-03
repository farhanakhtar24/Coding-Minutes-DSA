#include <iostream>
using namespace std;

int countBits(int n)
{
    int count = 0;
    while (n > 0) // TC of this loop is atmost Log(n) times for a number N ,as a number has log(n) bits atmost
    {
        int lastBit = n & 1;
        lastBit == 1 ? count++ : count;

        n = n >> 1;
    }

    return count;
}

int countBitsHack(int n) // its faster than previous versiion of this mehtod
{
    int count = 0;
    while (n > 0)
    {
        // removes the last set bit from the current number
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int num;
    cin >> num;
    cout << "Set Bits : " << countBits(num) << endl;
    cout << "Set Bits Using Hack: " << countBitsHack(num) << endl;
    return 0;
}