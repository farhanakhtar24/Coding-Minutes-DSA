#include <iostream>
#include <vector>

using namespace std;

void findSubSets(char *input, char *output, int i, int j)
{
    // base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    // recur case
    // include the letter
    output[j] = input[i];
    findSubSets(input, output, i + 1, j + 1);
    // dont include the letter
    findSubSets(input, output, i + 1, j);
}

int main()
{
    char input[100];
    char output[100];
    cout << "Find Subsets : ";
    cin >> input;
    findSubSets(input, output, 0, 0);
    return 0;
}