#include <iostream>
using namespace std;

int getIthBit(int number, int bit)
{
    // We will left shift the number 1 ,bit number of times : 1 << bit ;
    int mask = 1 << bit;

    if ((number & mask) > 0) // if mask & number is greater than 0 than that suggest that their is 1 as bit in that bit
    {
        return 1;
    }
    else if ((number & mask) == 0)
    {
        return 0;
    }
    return -1;

    // Or

    // return (number & mask) > 0 ? 1 : 0;
}

void setIthBit(int &number, int bit)
{
    // 1 is known as set bit
    int mask = 1 << bit;
    number = mask | number; // here we are putting set bit at the designated bit digit
}

void clearIthBit(int &number, int bit)
{
    // 0 is known as clear bit
    int mask = ~(1 << bit);
    number = number & mask;
}

void updateIthBit(int &number, int bit, int valueOfBit)
{
    clearIthBit(number, bit);
    int mask = valueOfBit << bit;
    number = number | mask;
}

int main()
{
    int num, bit;
    cout << "Number : ";
    cin >> num;

    cout << "Bit : ";
    cin >> bit;

    // setIthBit(num, bit);
    // clearIthBit(num, bit);
    // cout << "Bit : " << getIthBit(num, bit) << endl;
    updateIthBit(num, bit, 0);
    cout << num << endl;
    return 0;
}