/*

    Stanford University - Computer Science - Linked List Exercises

    Write a function AlternatingSplit() that takes one list and divides up its nodes to make
    two smaller lists. The sublists should be made from alternating elements in the original
    list. So if the original list is {a, b, a, b, a}, then one sublist should be {a, a, a}
    and the other should be {b, b}.

*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

int main(void)
{
    node* a = malloc(sizeof(node));
    a->data = 1;
    a->next = NULL;
    createList(a, 2);
    printList(a);                  //a list: 1 2


    node* b = malloc(sizeof(node));
    b->data = 7;
    b->next = NULL;
    append(b, 13);
    append(b, 1);
    printList(b);                  //b list: 7 13 1


    ShuffleMerge(a, b);            //result list: 1 7 2 13 1



}



