#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Run length encoding for string compression
// If the compressed string is bigger than the orignal string , then return the original string
// INPUT :aaabbccccddd
// OUTPUT : a3b2c4d3

// INPUT : abcd
// OUTPUT : abcd

string getcompressedString(string s)
{
    int n = s.length();
    string output;

    // The time complexity is linear here as we are not traversing the whole string in while loop

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 && s[i + 1] == s[i])
        {
            count++;
            i++;
        }
        output += s[i];
        output += to_string(count);
    }
    if (output.length() > s.length())
    {
        return s;
    }
    return output;
}

int main()
{
    string str1 = "aaabbccccddd";
    cout << getcompressedString(str1) << endl;
    return 0;
}
