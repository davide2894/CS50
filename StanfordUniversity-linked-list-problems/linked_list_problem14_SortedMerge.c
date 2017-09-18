/*

    Stanford University - Computer Science - Linked List Exercises

    Write a SortedMerge() function that takes two lists, each of which is sorted in increasing
    order, and merges the two together into one list which is in increasing order.
    SortedMerge() should return the new list.

*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

int main(void)
{
    node* a = malloc(sizeof(node));
    a->data = 1;
    append(a, 5);
    append(a, 7);
    printList(a);

    node* b = malloc(sizeof(node));
    b->data = 0;
    append(b, 3);
    append(b, 6);
    printList(b);

    SortedMerge(a, b);
}


