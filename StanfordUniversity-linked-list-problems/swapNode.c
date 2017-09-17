#include <stdio.h>
#include <stdlib.h>

#include "linked.h"


int main(void)
{
    node* head = malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;

    append(head, 7);
    append(head, 9);
    append(head, 3);
    printList(head); // 1 7 9 3

    node* current = head;
    node* next = current->next;

    swapNode(head, current, next); // 7 1 9 3


}
