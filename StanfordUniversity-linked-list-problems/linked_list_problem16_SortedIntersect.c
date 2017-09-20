/*

    Stanford University - Computer Science - Linked List - Exercises

    Given two lists sorted in increasing order, create and return a
    new list representing the intersection of the two lists.
    The new list should be made with its own memory — the
    original lists should not be changed.

*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
    Functions used from list.h
node* SortedIntersect(node* a, node* b)
{
    node* result = NULL;
    node** lastPtrRef = &result; //points to the last pointer in "result"

    //iterate until either list a or b run out
    while(a != NULL && b != NULL)
    {
        //compare nodes of the lists
        //if node a and b have equal elements
        if(a->data == b->data)
        {
            Push(lastPtrRef, a->data);
            //advance in both lists
            a = a->next;
            b = b->next;

            //advance to next ".next" in result
            lastPtrRef = &((*lastPtrRef)->next);
        }
        //advance the list which contains the smaller node
        else if(a->data < b->data)
            a = a->next;
        else
            b = b->next;
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
    node* a = BuildNewNode(6);
    Push(&a, 4);
    Push(&a, 3);
    Push(&a, 2);
    Push(&a, 1);

    //create list b
    node* b = BuildNewNode(9);
    Push(&b, 6);
    Push(&b, 3);
    Push(&b, 1);

    //print lists
    printf("List a: ");
    PrintList(a);               // 1 2 3 4 6 8
    printf("List b: ");
    PrintList(b);               //2 4 6 8


    //create new list which is the interesct between a and b
    node *intersect = SortedIntersect(a, b);

    //print it
    printf("Intersect list: ");
    PrintList(intersect);
}