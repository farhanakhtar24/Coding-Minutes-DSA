#include <iostream>
using namespace std;

//Pass by reference
void applyTax(int *income)
{
    float tax = 0.1;
    *income -= (*income * tax);
}

int main()
{
    int income;
    cin >> income;
    applyTax(&income);

    cout << "Income : " << income << endl;

    return 0;
}