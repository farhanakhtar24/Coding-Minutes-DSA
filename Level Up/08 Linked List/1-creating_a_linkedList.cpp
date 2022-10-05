#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *n = new Node(data);
    n->next = head;
    head = n;
}

void insertInTheMiddle(Node *head, int data, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, data);
    }
    else
    {
        Node *temp = head;
        for (int jump = 1; jump <= pos - 1; jump++)
        {
            temp = temp->next;
        }

        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    return;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    insertInTheMiddle(head, 100, 3);
    printLL(head);
    return 0;
}