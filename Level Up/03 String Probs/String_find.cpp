#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string para = "Hello jmi ke chappal chor laundo.ke";
    string word;
    getline(cin, word);

    // find function
    int index = para.find(word);
    if (index == -1)
    {
        cout << "word not found";
    }
    else
    {
        cout << "First Occurance : " << index << endl;
    }

    index = para.find(word, index + 1);

    if (index == -1)
    {
        cout << "2nd occurance not found";
    }
    else
    {
        cout << "Second Occurance : " << index;
    }

    return 0;
}