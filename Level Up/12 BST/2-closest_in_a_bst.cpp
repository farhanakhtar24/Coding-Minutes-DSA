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

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (key < root->data)
    {
        return insert(root->left, key);
    }
    else
    {
        return insert(root->right, key);
    }

    return root;
}

int closest(Node *root, int key)
{
    int close, diff;
    diff = INT_MAX;

    Node *temp = root;
    while (temp != NULL)
    {
        int curr_diff = abs(root->data - key);
        if (curr_diff == 0)
        {
            return root->data;
        }

        if (curr_diff < diff)
        {
            diff = curr_diff;
            close = root->data;
        }

        if (key > root->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return close;
}

int main()
{
    Node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int x : arr)
    {
        root = insert(root, x);
    }
    cout << closest(root, 8) << endl;

    return 0;
}