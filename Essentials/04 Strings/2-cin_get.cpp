/*
cin.get() allows to enter each character in a char array .
*/

#include <iostream>
using namespace std;

int main()
{
    char arr = cin.get();

    int length = 1;
    while (arr != '#')
    {
        cout << arr;
        arr = cin.get();
        length++;
    }

    cout << "\n"
         << "length : " << length << endl;

    // EXERCISE : Storing a whole sentence and then printing it out

    // char sentence[1000];
    // char iterator = cin.get();
    // int sentenceLength = 0;
    // while (iterator != '#')
    // {
    //     sentence[sentenceLength] = iterator;
    //     iterator = cin.get();
    //     sentenceLength++;
    // }

    // cout << sentence << endl;
    return 0;
}
