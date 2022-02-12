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

bool search(Node *root, int key) // T.C = O(height of tree)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }

    if (root->data > key)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *remove(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (key > root->data)
    {
        root->right = remove(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = remove(root->left, key);
    }
    else
    {
        // The real deleteion takes place here
        // when the current node matches with the key

        // No children
        // delete root
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // 1 child node
        // delete root node and connect it's child with it's parent root
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // 2 child nodes
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
        // Replace the root node's value with the inorder sucessor .i.e. smallest element in the right subtree of the root node
        return root;
    }
    return root;
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

    int key;
    cin >> key;

    root = remove(root, key);

    cout << endl;
    // cout << search(root, 14) << endl;
    printInorder(root);

    return 0;
}