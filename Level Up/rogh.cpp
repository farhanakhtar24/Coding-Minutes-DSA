#include <iostream>
#include <conio.h>
using namespace std;

class employee
{
    int empcode;
    char empname[50];

public:
    void getdata();
    void display();
};

void employee::getdata()
{
    cout << "Enter employee name: ";
    cin >> empname;
    cout << "Enter employee code: ";
    cin >> empcode;
}

void employee::display()
{
    cout << empname << "\t\t" << empcode;
    cout << " \n";
}

int main()
{
    int i, j;
    employee emp[8];
    cout << "Enter Employee details\n";
    for (i = 0; i < 8; i++)
    {
        emp[i].getdata();
    }
    cout << "Entered Employee details are\n";
    cout << "Employee name "
         << "\t"
         << "  Employee code   " << endl;
    for (j = 0; j < 8; j++)
    {
        emp[j].display();
    }
    return 0;
}
