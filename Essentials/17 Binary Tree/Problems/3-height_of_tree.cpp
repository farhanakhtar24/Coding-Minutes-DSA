#include <iostream>
#include <queue>
using namespace std;

// INPUT : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
