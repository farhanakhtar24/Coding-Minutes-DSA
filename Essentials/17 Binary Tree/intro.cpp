/*
In Binary trees each node can atmost have only 2 children nodes
*/

#include <iostream>
using namespace std;

// INPUT : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int dt)
    {
        data = dt;
        left = right = NULL;
    }
};

// Preorder build of the tree

Node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

// Root : left  : right
// OUTPUT : 1 2 4 5 7 3 6
void printPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// left : Root : right
// OUTPUT : 4 2 7 5 1 3 6
void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// left : right : Root
// OUTPUT : 4 7 5 2 6 3 1
void printPostorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = buildTree();

    cout << "Preorder : ";
    printPreorder(root);
    cout << endl;

    cout << "Inorder : ";
    printInorder(root);
    cout << endl;

    cout << "PostOrder : ";
    printPostorder(root);
    cout << endl;

    return 0;
}