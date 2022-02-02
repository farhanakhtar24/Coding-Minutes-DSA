#include <iostream>
#include <queue>
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

//Implement Level order Traversal :
/*
INPUT : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
Expected Output:
1
2 3 
4 5 6
7
*/

void printLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            // insert new null for next lvl
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
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
    return;
}

int main()
{
    Node *root = buildTree();
    printLevelOrderTraversal(root);
    return 0;
}