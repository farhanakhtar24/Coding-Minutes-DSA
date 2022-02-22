#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s{1, 2, 3, 8, 11, 15, 0};
    int key;
    cin >> key;

    if (s.find(key) != s.end())
    {
        cout << key << endl;
        ;
    }

    return 0;
}