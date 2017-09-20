/*

    Stanford University - Computer Science - Linked List Exercises

    Write a SortedMerge() function that takes two lists, each of which is sorted in increasing
    order, and merges the two together into one list which is in increasing order.
    SortedMerge() should return the new list.

*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
    Functions used from list.h

node* SortedMerge(node* a, node* b)
{
    //start result list as empty;
    node* result = NULL;

    //point to the last result pointer
    node** lastPtrRef = &result;

    while(1)
    {
        //if either a or b run out, take nodes from the other list
        if(a == NULL)
        {
            *lastPtrRef = b;
            break;
        }
        else if(b == NULL)
        {
            *lastPtrRef = a;
            break;
        }


        if(a->data < b->data)
            MoveNode(lastPtrRef, &a);
        else
            MoveNode(lastPtrRef, &b);

        lastPtrRef = &((*lastPtrRef)->next);            //move to the next ".next" pointer
    }
    return result;
}



node* BuildNewNode(int data)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


void Push(node** headRef, int newData)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
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
    //create list a
    node* a = BuildNewNode(5);
    Push(&a, 2);
    Push(&a, 1);
    //print it
    printf("List a: ");
    PrintList(a);

    //create list b
    node* b = BuildNewNode(4);
    Push(&b, 3);
    Push(&b, 0);
    //print it
    printf("List b: ");
    PrintList(b);

    //merge a and b so that result list is sorted
    printf("Using SortedMerge()...\n");
    node* result = SortedMerge(a, b);

    //print merged list
    printf("Merged list: ");
    PrintList(result);                  //0 1 2 3 4 5
}

