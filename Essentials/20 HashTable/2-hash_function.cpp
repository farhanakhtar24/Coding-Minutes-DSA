/*
Good Hash Function :-
1.Reduces chances of collison :- Distribute keys uniformaly over the table
2.Should be fast to compute
*/

#include <iostream>
#include "hashtable.h"
using namespace std;

int main()
{
    HashTable<int> hashT;
    hashT.insert("Mango", 100);
    hashT.insert("Apple", 120);
    hashT.insert("Banana", 140);
    hashT.insert("Orange", 160);
    hashT.insert("Grapes", 180);
    hashT.insert("Kiwi", 220);
    hashT.insert("Papapya", 260);
    hashT.insert("PineApple", 280);
    hashT.print();

    // Erasing nodes testing code
    // string fruit;
    // cin >> fruit;
    // hashT.erase(fruit);
    // hashT.print();

    // Searching testing code
    // string fruit;
    // cin >> fruit;
    // int *price = hashT.search(fruit);
    // bool presentOrNot = hashT.isPresent(fruit);

    // if (price != NULL)
    // {
    //     cout << "PRICE : " << *price << endl;
    // }
    // else
    // {
    //     cout << "Fruit not found" << endl;
    // }

    // [] operator testing code
    // hashT["Gorilla"] = 240;
    // cout << "Gorilla's cost is : " << hashT["Gorilla"] << endl;
    // hashT["Gorilla"] += 60;
    // cout << "Gorilla's updated cost is : " << hashT["Gorilla"] << endl;
    // hashT.print();
    return 0;
}
