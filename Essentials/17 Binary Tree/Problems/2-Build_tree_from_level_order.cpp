#include <iostream>
#include <queue>
using namespace std;

// INPUT : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

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

Node *BuildTreeLvlOrder()
{
    int d;
    cin >> d;

    Node *root = new Node(d);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftN, rightN;
        cin >> leftN >> rightN;

        if (leftN != -1)
        {
            temp->left = new Node(leftN);
            q.push(temp->left);
        }

        if (rightN != -1)
        {
            temp->right = new Node(rightN);
            q.push(temp->right);
        }
    }

    return root;
}

int main()
{
    Node *root = BuildTreeLvlOrder();
    // printLevelOrderTraversal(root);
    printLevelOrderTraversal(root);
    return 0;
}
