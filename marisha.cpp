#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int weight;
    cout << "What is your package weight in pounds : ";
    cin >> weight;
    int cost = 0;
    if (weight < 10)
    {
        cost = 20;
        cout << "Do you want a special delievery ? (y or n):";
        char ans;
        cin >> ans;
        if (ans == 'y')
        {
            cost += 5;
        }
    }
    else
    {
        cost = 30;
    }

    cout << "Your cost is : $" << cost << endl;
    return 0;
}