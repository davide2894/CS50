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
    node* source = malloc(sizeof(node));
    source->data = 1;
    source->next = NULL;
    append(source, 2);
    append(source, 3);
    append(source, 4);
    printList(source);                    //1 2 3 4 5 6

    AlternatingSplit(source);             //a list: 1 3
                                          //b list: 2 4
}