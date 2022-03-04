#include <bits/stdc++.h>
using namespace std;

class Trie;

class Node
{
    char data;
    unordered_map<char, Node *> map;
    bool isTerminal;

public:
    Node(char d)
    {
        data = d;
        this->isTerminal = false;
    }
    friend class Trie;
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }
    // Insertion
    void insert(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->map.count(ch) == 0)
            {
                Node *n = new Node(ch);
                temp->map[ch] = n;
            }
            temp = temp->map[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->map.count(ch) == 0)
            {
                return false;
            }
            temp = temp->map[ch];
        }
        return temp->isTerminal;
    }
    // Searching
};