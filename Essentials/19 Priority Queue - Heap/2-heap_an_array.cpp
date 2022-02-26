/*
Problem with heap as a binary tree is when we have to map a node , it takes a lot of time.
So we can convert a heap's binary tree to an array and map each node with the formula
   i
  / \
 2i 2i+1

this formula is possible because of the fact that the binary tree of heap is a completely filled tree
*/