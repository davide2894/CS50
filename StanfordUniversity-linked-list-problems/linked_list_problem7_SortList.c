/*
        Stanford University - Computer Science - Linked list exercises

        Given a list, change it so that it becomes sorted
        in increasing order
*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"


int main(void)
{

        node* head = malloc(sizeof(node));
        head->data = 7;
        head->next = NULL;

        append(head, 1);
        append(head, 9);
        append(head, 3);


        printList(head);  // 1 7 9 3

        SortList(head); // 1 3 7 9

        return 0;
}