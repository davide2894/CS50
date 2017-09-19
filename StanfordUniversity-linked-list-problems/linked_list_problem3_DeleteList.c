/*
        Stanford University - Computer Science - Linked list exercises

        Write a function DeleteList() that does the following:
        -takes a list
        -deallocates all of its memory
        -sets the new empty list's head pointer to NULL
*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
    Functions used from list.h


node* BuildOneTwoThree()
{
    node* head = malloc(sizeof(node));
    node* second = malloc(sizeof(node));
    node* third = malloc(sizeof(node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    //head points to the list
    return head;
}


void PrintList(node* head)
{
    node* current = head;

    while(current != NULL)
    {
        printf("%i ", current->data);
        current = current->next;
    }

    if(head == NULL)
    {
        printf("empty\n");
    }
}


void DeleteList(node** head)
{
    node* current = *head; //access real head in main
    node* next = current;

    while(current != NULL)
    {
        next = current->next;
        free(current);    //delete node
        current = next;   //advance to next node
    }

    *head = NULL;         //list in main is now empty
}

*/


int main(void)
{
    printf("List before deletion: ");
    node* myList = BuildOneTwoThree();      //1 2 3
    PrintList(myList);
    printf("\n");

    DeleteList(&myList);

    printf("List after deletion: ");        //empty
    PrintList(myList);
}
