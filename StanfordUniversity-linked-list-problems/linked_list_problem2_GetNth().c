/*
    Create a GetNth function that takes a linked list
    and an integer index and returns the value
    stored in the node at that index position
*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"


int GetNth(node* head, int index_to_find)
{
    //create node to traverse, then assign head data and link to it
    node* current = head;

    //set count to 0
    int count = 0;

    //traverse list until the end
    while(current != NULL)
    {
        if(count == index_to_find)
        {
            printf("data value %i is at index %i\n", current->data, index_to_find);
            break;
        }
        else
        {
            //move current to the next node
            current = current->next;

            //update counr
            count++;
        }
    }

    //assert fail if we get here, because it would mean
    //the index we are looking for is not in the list
    if(current==NULL && index_to_find != count)
    {
        printf("node of index %i is not in the list\n", index_to_find);
        return 1;
    }
    else
        return 0;
}


int main(void)
{
    node* head = malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;

    createList(head, 5);
    printList(head);

    GetNth(head, 4);
}