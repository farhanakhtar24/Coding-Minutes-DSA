#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dec_to_bin(int no)
{
    int decimalNo = no;
    stack<char> remainders;
    int rem, i = 0;
    char *output;

    while (no != 0)
    {
        rem = no % 2;
        if (rem >= 10)
            rem += 55;
        else
            rem += 48;

        remainders.push(rem);
        no = no / 2;
    };
    cout << "The binary no. for " << decimalNo << " is ";
    while (!remainders.empty())
    {
        cout << remainders.top();
        remainders.pop();
    }
    cout << "\n";
}
void dec_to_oct(int no)
{
    int decimalNo = no;
    stack<char> remainders;
    int rem, i = 0;
    char *output;

    while (no != 0)
    {
        rem = no % 8;
        if (rem >= 10)
            rem += 55;
        else
            rem += 48;

        remainders.push(rem);
        no = no / 8;
    };
    cout << "The octal no. for " << decimalNo << " is ";
    while (!remainders.empty())
    {
        cout << remainders.top();
        remainders.pop();
    }
    cout << "\n";
}
void dec_to_hexadecimal(int no)
{
    int decimalNo = no;
    stack<char> remainders;
    int rem, i = 0;
    char *output;

    while (no != 0)
    {
        rem = no % 16;
        if (rem >= 10)
            rem += 55;
        else
            rem += 48;

        remainders.push(rem);
        no = no / 16;
    };
    cout << "The hexa decimal no. for " << decimalNo << " is ";
    while (!remainders.empty())
    {
        cout << remainders.top();
        remainders.pop();
    }
    cout << "\n";
}
void dec_to_any_base(int no, int base)
{
    int decimalNo = no;
    stack<char> remainders;
    int rem, i = 0;
    char *output;

    while (no != 0)
    {
        rem = no % base;
        if (rem >= 10)
            rem += 55;
        else
            rem += 48;

        remainders.push(rem);
        no = no / base;
    };
    cout << "The no. in base " << base << " for " << decimalNo << " is ";
    while (!remainders.empty())
    {
        cout << remainders.top();
        remainders.pop();
    }
    cout << "\n";
}
int to_decimal(char *no, int base)
{
    int i, ans = 0, factor = 1, count = 0;
    for (i = 0; no[i] != '\0'; i++)
        count++;
    for (i = count - 1; i >= 0; i--)
    {
        if (no[i] >= 'A' && no[i] <= 'F')
            ans += (no[i] - 55) * factor;
        else if (no[i] >= 'a' && no[i] <= 'f')
            ans += (no[i] - 87) * factor;
        else if (no[i] >= '0' && no[i] <= '9')
            ans += (no[i] - 48) * factor;
        factor *= base;
    }
    return ans;
}

int main()
{
    cout << "\n Name: Mohammad Faraz Idris Siddiqui\n";
    int choice, base, num_decimal, deci, base2, count = 0;
    char num_any_base[100];
    char *answer_decimal;
    while (1)
    {
        cout << "\n1. Decimal to Binary.";
        cout << "\n2. Decimal to Octal.";
        cout << "\n3. Decimal to Hexadecimal.";
        cout << "\n4. Decimal to any base.";
        cout << "\n5. Binary to decimal.";
        cout << "\n6. Octal to decimal";
        cout << "\n7. Hexadecimal to decimal.";
        cout << "\n8. Any base to decimal.";

        cout << "\n9. to Exit!\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the decimal no. : ";
            cin >> num_decimal;
            dec_to_bin(num_decimal);

            break;
        case 2:
            cout << "Enter the decimal no. : ";
            cin >> num_decimal;
            dec_to_oct(num_decimal);

            break;
        case 3:
            cout << "Enter the decimal no. : ";
            cin >> num_decimal;
            dec_to_hexadecimal(num_decimal);

            break;
        case 4:
            cout << "Enter the no. : ";
            cin >> num_decimal;
            cout << "Enter the base of the no. in which you want to convert : ";
            cin >> base;
            dec_to_any_base(num_decimal, base);

            break;
        case 5:
            cout << "Enter the binary no. : ";
            cin >> num_any_base;
            cout << "The decimal no. for " << num_any_base << " is " << to_decimal(num_any_base, 2) << endl;
            break;
        case 6:
            cout << "Enter the octal no. : ";
            cin >> num_any_base;
            cout << "The decimal no. for " << num_any_base << " is " << to_decimal(num_any_base, 8) << endl;
            break;
        case 7:
            cout << "Enter the hexadecmial no. : ";
            cin >> num_any_base;
            cout << "The decimal no. for " << num_any_base << " is " << to_decimal(num_any_base, 16) << endl;
            break;
        case 8:
            cout << "Enter the base of the no.in which you want to convert : ";
            cin >> base;
            cout << "Enter the no. : ";
            cin >> num_any_base;
            cout << "The decimal no. for " << num_any_base << " is " << to_decimal(num_any_base, base) << endl;
            break;
        case 9:
            exit(1);

            break;

        default:
            cout << "Invalid input!\n";
            break;
        }
    }
    return 0;
}
