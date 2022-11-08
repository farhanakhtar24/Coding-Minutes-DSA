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

bool maxSubsetSum(Node *node, int &currSum)
{
    if (node == NULL)
    {
        return true;
    }

    bool left = maxSubsetSum(node->left, currSum);
    bool right = maxSubsetSum(node->right, currSum);

    if (left && right)
    {
        currSum += node->data;
        return false;
    }

    return true;
}

int main()
{
    Node *root = buildTree();
    int currSum = 0;
    bool ans = maxSubsetSum(root, currSum);
    cout << currSum << endl;
    return 0;
}