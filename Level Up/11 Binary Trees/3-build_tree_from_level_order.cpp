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

Node *buildTreeLvlOrder()
{
    int n;
    cin >> n;

    queue<Node *> q;
    Node *root = new Node(n);
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        int left, right;
        cin >> left >> right;
        if (left != -1)
        {
            Node *leftN = new Node(left);
            front->left = leftN;
            q.push(leftN);
        }
        if (right != -1)
        {
            Node *rightN = new Node(right);
            front->right = rightN;
            q.push(rightN);
        }
    }
    return root;
}

void printLevelOrderTravesal(Node *root)
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
        if (temp)
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
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        cout << endl;
    }
}

int main()
{
    // INPUT : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node *root = buildTreeLvlOrder();
    printLevelOrderTravesal(root);
    return 0;
}