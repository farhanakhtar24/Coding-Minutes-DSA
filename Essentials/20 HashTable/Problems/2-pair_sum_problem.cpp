#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// TC: O(n)
void pairSum(vector<int> &arr, int key)
{
    unordered_set<int> table;
    for (int i = 0; i < arr.size(); i++)
    {
        int result = key - arr[i];
        if (table.find(result) != table.end())
        {
            cout << "(" << arr[i] << "," << result << ")" << endl;
        }
        else
        {
            table.insert(arr[i]);
        }
    }
}

int main()
{
    vector<int> arr{10, 5, 2, 3, -6, 9, 11};
    int key;
    cin >> key;
    pairSum(arr, key);
    return 0;
}