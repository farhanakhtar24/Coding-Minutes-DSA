#include <iostream>
#include <vector>
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

void printVector(vector<int> &items)
{
    for (int i : items)
    {
        cout << i << "->";
    }
}

void printPath(Node *root, vector<int> &items)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        printVector(items);
        cout << root->data << "->";
        cout << endl;
        return;
    }

    // recursive case
    items.push_back(root->data);
    printPath(root->left, items);
    printPath(root->right, items);
    // Backtracking case
    items.pop_back();
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

    // printInorder(root);
    vector<int> elements;
    printPath(root, elements);
    return 0;
}