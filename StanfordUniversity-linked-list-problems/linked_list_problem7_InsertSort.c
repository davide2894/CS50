 /*
        Stanford University - Computer Science - Linked list exercises

        Given a list, change it so that it becomes sorted
        in increasing order
*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"


/*

Functions used from list.h

node* BuildNewNode(int data)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
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


void InsertSort(node** headRef)
{
    node* result = NULL;       //start result list with NULL
    node* current = *headRef;
    node* next;

    //iterate down the list
    while(current != NULL)
    {
        //set next node to current->next
        //before using SortedInsert()
        //on current
        next = current->next;

        SortedInsert(&result, current);

        //advance to next node
        current = next;
    }

    *headRef = result;
}



*/



int main(void)
{
        node* myList = BuildNewNode(5);
        Push(&myList, 7);
        Push(&myList, 9);
        PrintList(myList);  //9 7 5

        printf("myList->data %i\n", myList->data);

        InsertSort(&myList);
        PrintList(myList);  //5 7 9
}
