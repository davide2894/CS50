/*
        Stanford University - Computer Science - Linked list exercises

        Write a Pop() function that does the following:
        -takes a non-empty list
        -deletes the head node
        -returns head node's data
*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"


void Pop(node** head)
{
    node* current = *head;
    node* new_head = current->next;

    free(current);

    *head = new_head;

}

int main(void)
{
    node* head = malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;

    //create a list
    createList(head, 3);

    //print it
    printList(head);


    //pop head
    Pop(&head);

    //reprint to verify
    printList(head);


    //success
    return 0;
}