#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> menu;

    // Inserting key : value pairs in hashTable
    // Insertion : O(1)
    menu["maggi"] = 20;
    menu["colddrink"] = 20;
    menu["dosa"] = 99;
    menu["pizza"] = 499;
    menu["indianPlatter"] = 399;

    // update query : O(1)
    menu["dosa"] = (1 + 0.1) * menu["dosa"];

    // Deletion : O(1)
    menu.erase("dosa");

    // Search inside the items : O(1)
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