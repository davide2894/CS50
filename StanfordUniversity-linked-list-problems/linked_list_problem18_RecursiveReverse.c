/*

    Stanford University - Computer Science - Linked List Exercises

    Make Reverse() recursive
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
    Functions used from "list.h"

void RecursiveReverse(node** headRef)
{
    node* a;
    node* b;

    if(*headRef == NULL)
    return;

    a = *headRef;    //1 2 3
    b = a->next;     //  2 3

    if(b == NULL)
        return;

    RecursiveReverse(&b);

    a->next->next = a; //put first element at the end of the list
    a->next = NULL;    //cut list a after first element


    *headRef = b;
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
    //create list
    node* myList = BuildOneTwoThree();
    //print it
    printf("list: ");
    PrintList(myList);


    //applying recursive reverse function
    printf("Applying RecursiveReverse()...\n");
    RecursiveReverse(&myList);

    //print reversed list
    printf("List reversed with recursion: ");
    PrintList(myList);
}