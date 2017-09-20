/*
    Stanford University - Computer Science - Linked List - Exercises

    Write an iterative Reverse() function that reverses a list by rearranging all the .next
    pointers and the head pointer.
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
    Functions used from list.h

void Reverse(node** headRef)
{
    node* result = NULL;
    node* current = *headRef;


    while(current != NULL)
    {
        //move headRef node to result and make it its head
        MoveNode(&result, &current);
    }
    //change headRef, now points to result's head
    *headRef = result;
}


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
    if(head == NULL)
    {
        printf("empty\n");
    }
    else
    {
        node* current = head;

        while(current != NULL)
        {
            printf("%i ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}


*/

int main(void)
{
    //create a list and print it
    node* myList = BuildOneTwoThree(); // 1 2 3
    printf("List: ");
    PrintList(myList);

    printf("Reversing list...\n");
    Reverse(&myList);

    printf("Reversed list: ");
    PrintList(myList);                 // 3 2 1
}