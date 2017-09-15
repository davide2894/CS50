/*
        Stanford University - Computer Science - Linked list exercises

        Write a function DeleteList() that does the following:
        -takes a list
        -deallocates all of its memory
        -sets the new empty list's head pointer to NULL
*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"


void DeleteList(node** head)
{
    node* current = *head;
    node* Next;

    while(current != NULL)
    {
        //allocate Next to the node after current
        Next = current->next;

        //free current from memory
        free(current);

        //move current to the next node
        current = Next;
    }

    //reallocate the head to NULL
    // *head to affect the real head
    *head = NULL;
}


int main(void)
{
    node* head = malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;

    //create a list
    createList(head, 5);

    //print it
    printList(head);

    //deallocate the entire list
    DeleteList(&head);

    //reprint list to verify
    printList(head);

    return 0;
}