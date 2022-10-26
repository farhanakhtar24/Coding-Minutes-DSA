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
        right = NULL;
        left = NULL;
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
    Node *newNode = new Node(n);
    newNode->left = buildTree();
    newNode->right = buildTree();

    return newNode;
}

void printLvlOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int replaceSum(Node *root, int currSum)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int leftSum = replaceSum(root->left, currSum);
    int rightSum = replaceSum(root->right, currSum);

    currSum = leftSum + rightSum + root->data;
    root->data = leftSum + rightSum;
    return currSum;
}

int main()
{
    Node *root = buildTree();
    int ans = replaceSum(root, 0);
    printLvlOrder(root);
    return 0;
}