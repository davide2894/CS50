/*
        Stanford University - Computer Science - Linked list exercises

        Write a function called InsertNth which can insert a new node
        at any index within a list.
        Given a list, an index 'n' in the range 0..length,
        and a data element, add a new node to the list so
        that it has the given index.

*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"


/*

Functions used from list.h

void InsertNth(node** head, int index, int data)
{
    node* current = *head;

    if(index == 0)
        Push(head, data);
    else
    {
        for(int i = 0; i < index-1; i++)
        {
            current = current->next; //reach desired index position
        }
        Push(&(current->next), data); //push in front of the next node
                                      //i.e. at the desired index
    }
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



*/





int main(void)
{
        node* head = NULL;  //start with empty list
        InsertNth(&head, 0, 1);
        InsertNth(&head, 1, 3);
        InsertNth(&head, 1, 5);
        PrintList(head);        //1 3 5


}
