/*

    Stanford University - Computer Science - Linked List Exercises

    Given a list, split it into two sublists — one for the front half, and one for the back half.
    If the number of elements is odd, the extra element should go in the front list.
    So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7,11}.

*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

int main(void)
{
    node* a = malloc(sizeof(node));
    node* b = malloc(sizeof(node));

    //create list with 1 node, split it
    node* head0 = malloc(sizeof(node));
    head0->data = 2;
    head0->next = NULL;
    append(head0, 3);
    append(head0, 5);
    append(head0, 7);
    append(head0, 11);


    FrontBackSplit(head0, a, b);                       // A list: 2 3 5 | B list: 7 11
}
