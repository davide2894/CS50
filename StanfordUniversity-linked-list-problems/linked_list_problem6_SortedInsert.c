/*
        Stanford University - Computer Science - Linked list exercises

        Given a list sorted in increasing order, and a single node,
        write a SortedInsert() function that inserts the node into
        the correct sorted position in the list.
*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"



/*

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
    printf("\n");

    if(head == NULL)
    {
        printf("empty\n");
    }
}



void SortedInsert(node** headRef, node* newNode)
{

    if(*headRef == NULL || newNode <= *headRef)
    {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else
    {
        node* current = *headRef;

        //as long as is not the end of the list
        //and the next node is smaller than the new node
        while(current->next != NULL && current->next->data < newNode->data)
        {
            //move current to the next node
            current = current->next;
        }
        newNode->next = current->next; //link new node to the next
        current->next = newNode;       //link current to new node
    }
}




*/


int main(void)
{
        node* myList = BuildOneTwoThree();
        PrintList(myList);

        node* newNode = BuildNewNode(5);
        printf("newnode %i\n", newNode->data);

        SortedInsert(&myList, newNode);

        printf("List with sorted insert: ");
        PrintList(myList);
}
