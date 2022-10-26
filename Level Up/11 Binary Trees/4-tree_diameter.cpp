#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2) + 1;
}

int diameter(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // rec case
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));
}

// Diameter Optimised

int main()
{
    // INPUT : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node *root = buildTree();
    cout << diameter(root);
    return 0;
}