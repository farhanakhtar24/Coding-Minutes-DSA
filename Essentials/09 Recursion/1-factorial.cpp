#include <iostream>
using namespace std;

int factorial(int n)
{
    //base Case
    if (n == 0)
    {
        return 1;
    }
    //recursive case
    else
    {
        int ans = n * factorial(n - 1);
        return ans;
    }
}

int main()
{
    int num;
    cin >> num;
    cout << factorial(5) << endl;
    return 0;
}