#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) : data(d), left(NULL), right(NULL){};
};

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

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

void printInRange(Node *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= k1 && root->data <= k2)
    {
        // call on both sides
        printInRange(root->left, k1, k2);
        cout << root->data << " ";
        printInRange(root->right, k1, k2);
    }
    else if (root->data > k2)
    {
        printInRange(root->left, k1, k2);
    }
    else if (root->data < k1)
    {
        printInRange(root->right, k1, k2);
    }
}

int main()
{
    Node *root = NULL;
    Node *temp = root;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int x : arr)
    {
        root = insert(root, x);
        // cout << root->data << endl;
    }

    printInorder(root);
    cout << endl;
    int k1, k2;
    cin >> k1 >> k2;
    printInRange(root, k1, k2);

    return 0;
}