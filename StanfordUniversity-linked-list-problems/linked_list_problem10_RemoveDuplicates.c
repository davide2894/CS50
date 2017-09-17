/*

    Stanford University - Computer Science - Linked List Exercises

    Write a RemoveDuplicates() function which takes a list sorted in increasing order and
    deletes any duplicate nodes from the list. Ideally, the list should only be traversed once

*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

int main(void)
{
    node* head = malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;
    printList(head);                    //1 2 2 3 3
    append(head, 2);
    append(head, 2);
    append(head, 3);
    append(head, 3);

    RemoveDuplicates(head);             //1 2 2 3 3


    printf("\n");

    //case with no duplicates
    node* head2 = malloc(sizeof(node));
    head2->data = 1;
    head2->next = NULL;

    RemoveDuplicates(head2);             //No duplicate to remove
                                         //list: 1

    return 0;
}
