#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of students : ";
    cin >> n;
    // here we have dynmaically allocated array size
    int marks[n] = {0};

    // INPUT
    for (int i = 0; i < 5; i++)
    {
        cin >> marks[i];
        marks[i] * 2;
    }

    //OUTPUT
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ,";
    }

    return 0;
}
