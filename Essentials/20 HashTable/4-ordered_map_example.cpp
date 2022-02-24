#include <iostream>
#include <map>
using namespace std;

// Now all order 1 queries will become logN queries as the map ds implements a slef balancing binary tree internally
// the key value pairs are sorted lexographically (according to the alphabetical order of the key's 1st letter)

int main()
{
    map<string, int> menu;

    // Inserting key : value pairs in hashTable
    // Insertion : O(logN)
    menu["maggi"] = 20;
    menu["colddrink"] = 20;
    menu["dosa"] = 99;
    menu["pizza"] = 499;
    menu["indianPlatter"] = 399;

    // update query : O(logN)
    menu["dosa"] = (1 + 0.1) * menu["dosa"];

    // Deletion : O(logN)
    menu.erase("dosa");

    // Search inside the items : O(logN)
    string item;
    cin >> item;

    if (menu.count(item) == 0)
    {
        cout << item << " is not available" << endl;
    }
    else
    {
        cout << item << " is available, and costs " << menu[item] << endl;
    }

    for (pair<string, int> item : menu)
    {
        cout << item.first << " : " << item.second << endl;
    };
    return 0;
}