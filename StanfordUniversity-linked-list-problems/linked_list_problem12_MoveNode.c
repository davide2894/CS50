/*
    Stanford University - Computer Science - Linked List - Exercises

    MoveNode() takes two lists, removes the front node from the second list and pushes
    it onto the front of the first

*/


#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main(void)
{
    node* a = malloc(sizeof(node));
    a->data = 1;
    a->next = NULL;
    append(a, 2);
    append(a, 3);
    printList(a);            //1 2 3

    node* b = malloc(sizeof(node));
    b->data = 4;
    b->next = NULL;
    append(b, 5);
    append(b, 6);
    printList(b);            //4 5 6


    MoveNode(&a, &b);       //a list: 4 1 2 3
                            //b list: 5 6

}