/*
Linked list is nothing but just a set of nodes which are connected linearly in a form of a chain
Node : it is a container which stores data in a sequence

The difference between arrays , vector and linked lists is that the data stored in in countinous memeory in arrays
whereas in linkedlists data is stored on demend and memeory is created on the fly
*/

/*
BASIC OPERATION :
1.Insertion : Head, Tail, Middle
2.Searching : Iteratively, Recursively
3.Deletion : Head, Tail, Middle
4.Creating a linkedList : Using insertion 
5.Deleting a linkedList : Using deletion 
6.Printing a linkedList  
*/

#include <iostream>
#include "./list.h"

using namespace std;

int main()
{
    LinkedList l1;
    l1.pushFront(1);
    l1.pushFront(2);
    l1.pushFront(3);
    l1.pushFront(4);
    l1.pushFront(5);
    l1.pushFront(6);
    l1.pushBack(13);
    l1.reverseList();
    // l1.remove(2);
    // l1.insert(3, 2);
    // l1.popFront();
    // l1.popBack();

    Node *head = l1.begin();
    while (head != nullptr)
    {
        cout << head->getData() << "->";
        head = head->next;
    }
    // cout << "Index : " << l1.recursiveSearch(0) << endl;
    return 0;
}