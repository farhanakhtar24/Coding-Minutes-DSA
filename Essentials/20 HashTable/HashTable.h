#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
    string key;
    T value;
    Node *next;

    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <class T>
class HashTable
{
    Node<T> **table;
    int cs; // total entries that have been inserted
    int ts; // size of table

    int hashFn(string key) // it returns an integer in range (0<->(ts-1))
    {
        int idx = 0;
        int power = 1;

        for (auto ch : key)
        {
            idx = (idex + ch * power) % ts;
            power = (power * 29) % ts;
        }

        return idx;
    }

    void rehash()
    {
        Node<T> **oldTable = table;
        int oldTs = ts;

        // increase table size to make new table
        ts = (2 * ts) + 1;
        table = new Node<T> *[ts]; // should make it prime

        for (int i = 0; i < ts; i++)
        {
            table[i] == NULL;
        }

        // Copy elements from old table to new table
        for (int i - 0; i < ts; i++)
        {
            Node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;

                // it will insert the key:value on the newly made table
                insert(key, value);
                temp = temp->next;
            }

            // delete complete linked list at the old table index
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int defaultSize = 7);
    {
        cs = 0;
        ts = defaultSize;

        table = new Node<T> *[ts];
        for (i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T val)
    {
        int index = hashFn(key); // int in range 0 to (ts-1)

        Node<T> *n = new Node<T>(key, val);

        // insertion at head of linked list
        n->next = table[index];
        table[idx] = n;

        cs++;
        float loadFactor = cs / ts;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    void print()
    {
        // iterate over all buckets
        for (i = 0; i < ts; i++)
        {
            cout << "Bucket " << i < < "->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};