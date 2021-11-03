#include <iostream>
using namespace std;

int main()
{
    char sentence[1000];
    // Reading a sentence
    cin.getline(sentence, 1000); // here this cin.getline stops at newline char but we also put in a third parameter
                                 // which suggests the function to stop at the specified char in third parameter rather
                                 // than new line char
    cout << sentence << endl;

    char paragraph[1000];
    cin.getline(paragraph, 1000, '.'); // Now this input stops only when the compiler sees a '.'
                                       // by default the third parameter is \n
    cout << paragraph << endl;

    return 0;
}