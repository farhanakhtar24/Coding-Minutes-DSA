/*
Unordered set also works on hashing
Just like unordered map each operation takes O(1) time on avg
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    // each insertion : O(1)
    unordered_set<int> s{1, 2, 3, 8, 11, 15, 0};
    int key;
    cin >> key;

    // searhing : O(1)
    if (s.find(key) != s.end())
    {
        cout << key << endl;
    }

    // insertion :O(1)
    s.insert(111);

    // erasing : O(1)
    s.erase(11);
    for (auto x : s)
    {
        cout << x << " "; // random order
    }

    return 0;
}