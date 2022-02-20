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
            idx = (idx + ch * power) % ts;
            power = (power * 29) % ts;
        }

        return idx;
    }

    void rehash()
    {
        Node<T> **oldTable = table;
        int oldTs = ts;
        cs = 0;
        // increase table size to make new table
        ts = (2 * ts) + 1;
        table = new Node<T> *[ts]; // should make it prime

        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }

        // Copy elements from old table to new table
        for (int i = 0; i < oldTs; i++)
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
    HashTable(int defaultSize = 7)
    {
        cs = 0;
        ts = defaultSize;

        table = new Node<T> *[ts];
        for (int i = 0; i < ts; i++)
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
        table[index] = n;

        cs++;
        float loadFactor = cs / ts;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    bool isPresent(string key)
    {
        int index = hashFn(key);
        Node<T> *temp = table[index];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    T *search(string key)
    {
        if (isPresent(key))
        {
            int index = hashFn(key);
            Node<T> *temp = table[index];

            while (temp != NULL)
            {
                if (temp->key == key)
                {
                    return &temp->value;
                }
                temp = temp->next;
            }
        }
        return NULL;
    }

    void erase(string key)
    {
        if (isPresent(key))
        {
            int index = hashFn(key);
            Node<T> *temp = table[index];

            // to delete head
            if (temp->key == key)
            {
                table[index] = temp->next;
                delete temp;
                return;
            }

            // to delete in the middle of a list
            Node<T> *prevTemp = new Node<T>("", 0);
            prevTemp->next = temp;
            while (temp != NULL)
            {
                if (temp->key == key)
                {
                    prevTemp->next = temp->next;
                    delete temp;
                    return;
                }
                temp = temp->next;
                prevTemp = prevTemp->next;
            }
        }
        else
        {
            cout << "Cant Erase as the key is not present" << endl;
        }
    }

    void print()
    {
        // iterate over all buckets
        for (int i = 0; i < ts; i++)
        {
            cout << "Bucket " << i << "->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T &operator[](string key)
    {
        // return the value
        // if key is not found then create a new node and return
        // return the existing node
        T *valueFound = search(key);
        if (valueFound == NULL)
        {
            T object;
            insert(key, object);
            valueFound = search(key);
        }
        return *valueFound;
    }
};