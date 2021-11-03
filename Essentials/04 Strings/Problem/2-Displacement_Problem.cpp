#include <iostream>
using namespace std;

int main()
{
    // Find shortest route between starting and finish point .i.e. displacement
    char route[1000];
    cin.getline(route, 1000);

    int y = 0, x = 0;

    // AlGO
    for (int i = 0; route[i] != '\0'; i++)
    {
        switch (route[i])
        {
        case 'N':
            y++;
            break;
        case 'E':
            x++;
            break;
        case 'S':
            y--;
            break;
        case 'W':
            x--;
            break;
        }
    }

    cout << x << " " << y << endl;

    // First quadrant
    if (x > 0 && y > 0)
    {
        while (x > 0)
        {
            cout << "E";
            x--;
        }
        while (y > 0)
        {
            cout << "N";
            y--;
        }
    }
    // Second quadrant
    else if (x < 0 && y > 0)
    {
        while (x < 0)
        {
            cout << "W";
            x++;
        }
        while (y > 0)
        {
            cout << "N";
            y--;
        }
    }
    // Third quadrant
    else if (x < 0 && y < 0)
    {
        while (x < 0)
        {
            cout << "W";
            x++;
        }
        while (y < 0)
        {
            cout << "S";
            y++;
        }
    }
    // Fourth quadrant
    else if (x > 0 && y < 0)
    {
        while (x > 0)
        {
            cout << "E";
            x--;
        }
        while (y < 0)
        {
            cout << "S";
            y++;
        }
    }

    return 0;
}