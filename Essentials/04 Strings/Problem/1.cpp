#include <iostream>
using namespace std;

//Given a sentence, countthe number of alphabets,digits and spaces in the sentence

int main()
{
    char ch;

    // Count
    int aplhabets = 0, space = 0, digits = 0;
    ch = cin.get();

    // Suing ASCII notations we can do this question

    while (ch != '\n')
    {
        if (ch >= '0' && ch <= '9')
        {
            digits++;
        }
        else if ((ch >= 'a' && ch <= 'z') || ch >= 'A' && ch <= 'Z')
        {
            aplhabets++;
        }
        else if (ch == ' ' || ch == '\t') // \t is tab which also a kind of space
        {
            space++;
        }
        ch = cin.get();
    }

    cout << "Alphabets: " << aplhabets << endl
         << "Spaces: " << space << endl
         << "Digits: " << digits << endl;

    return 0;
}
