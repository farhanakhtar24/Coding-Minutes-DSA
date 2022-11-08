#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int d)
    {
        data = d;
        right = left = NULL;
    }
};

Node *buildTree()
{
    int n;
    cin >> n;

    if (n == -1)
    {
        return NULL;
    }

    Node *temp = new Node(n);
    temp->left = buildTree();
    temp->right = buildTree();

    return temp;
}

// O(N)
pair<bool, int> heightBalancedTree(Node *root)
{
    pair<bool, int> p, right, left;
    if (root == NULL)
    {
        return {true, 0};
    }

    left = heightBalancedTree(root->left);
    right = heightBalancedTree(root->right);

    p.first = left.first && right.first;
    p.second = max(left.second, right.second) + 1;

    if (abs(left.second - right.second) <= 1 && p.first)
    {
        return {true, p.second};
    }

    return {false, p.second};
}

int main()
{
    // INPUT : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node *root = buildTree();
    pair<bool, int> p = heightBalancedTree(root);
    if (p.first)
    {
        cout << "Height balanced tree" << endl;
    }
    else
    {
        cout << "Not a height balanced tree" << endl;
    }
    return 0;
}