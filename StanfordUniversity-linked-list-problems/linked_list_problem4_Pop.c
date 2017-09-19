/*
        Stanford University - Computer Science - Linked list exercises

        Write a Pop() function that does the following:
        -takes a non-empty list
        -deletes the head node
        -returns head node's data
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


int Length(node* head)
{
    node* current = head;
    int count = 0;

    while(current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}



int Pop(node** head)
{
    node* current = *head;      //access real head in main
    node* next = current->next;
    *head = next;               //change head to next node

    int popped = current->data;       //store popped value

    free(current);              //delete ex head

    return popped;
}

*/



int main(void)
{
    node* myList = BuildOneTwoThree();      //1 2 3
    PrintList(myList);
    printf("\n");

    int a = Pop(&myList); //deletes 1 and returns it
    printf("Popped %i from list\n", a);

    int b = Pop(&myList); //deletes 2 and returns it
    printf("Popped %i from list\n", b);

    int c = Pop(&myList);  //deletes 3 and returns it
    printf("Popped %i from list\n", c);

    int len = Length(myList); //list is empty so len = 0
    printf("List length is now %i\n", len);
}
