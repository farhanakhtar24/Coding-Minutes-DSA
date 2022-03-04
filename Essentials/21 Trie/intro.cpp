/*

***** PREFIX TRIE *****
Generic Tree like data staructure(can have more than 2 child nodes)
Efficient info retrieval data structure
Searches in optimal time O(key length) but uses extra storage(tradeoff)

Important Operation :
1. Search for a word
2. Insert a new word
3. Deletion

*/

#include <iostream>
#include "./trie.h"
using namespace std;

int main()
{
    string words[] = {"hello", "he", "apple", "news", "aple"};
    Trie tree;
    for (auto x : words)
    {
        tree.insert(x);
    }

    string key;
    cin >> key;
    cout << tree.search(key) << endl;
    return 0;
}