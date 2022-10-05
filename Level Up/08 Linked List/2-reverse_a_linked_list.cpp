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

Node *reverseIterative(Node *&head)
{
    Node *pre = NULL;
    Node *curr = head;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    head = pre;
    return pre;
}

// Node *kReverse(Node *&head, int k)
// {
//     Node *pre = NULL;
//     Node *curr = head;
//     Node *next;

//     int count = 0;
//     while (curr != NULL && count <= k)
//     {
//         next = curr->next;
//         curr->next = pre;
//         pre = curr;
//         curr = next;
//     }
// }

Node *midpoint(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *list1, Node *list2)
{
    Node *l1 = list1;
    Node *l2 = list2;

    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }

    if (l1 == NULL || l2 == NULL)
    {
        return l1 == NULL ? l2 : l1;
    }

    Node *head = new Node(0);
    head->next = l1->data <= l2->data ? l1 : l2;

    head = head->next;

    Node *temp;
    if (l1->data <= l2->data)
    {
        temp = l1;
        l1 = l1->next;
    }
    else
    {
        temp = l2;
        l2 = l2->next;
    }

    while (l1 != NULL && l2 != NULL)
    {
        if (l2->data <= l1->data)
        {
            temp->next = l2;
            // temp=temp->next;
            l2 = l2->next;
        }
        else if (l1->data <= l2->data)
        {
            temp->next = l1;
            // temp=temp->next;
            l1 = l1->next;
        }
        temp = temp->next;
    }

    while (l1 != NULL)
    {
        temp->next = l1;
        l1 = l1->next;
        temp = temp->next;
    }

    while (l2 != NULL)
    {
        temp->next = l2;
        l2 = l2->next;
        temp = temp->next;
    }

    return head;
}

Node *mergeSort(Node *head)
{
    // basee case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = midpoint(head);

    Node *a = head;
    Node *b = head->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    // Merge
    return merge(a, b);
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    printLL(head);
    cout << endl;
    head = mergeSort(head);
    // reverseIterative(head);
    printLL(head);

    return 0;
}