/*

    Stanford University - Computer Science - Linked List Exercises

    Given two lists, merge their nodes together to make one list, taking nodes alternately
    between the two lists. So ShuffleMerge() with {1, 2, 3} and {7, 13, 1} should yield {1, 7,
    2, 13, 3, 1}. If either list runs out, all the nodes should be taken from the other list.

*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
    Functions used from list.h

node* ShuffleMerge(node* a, node* b)
{
    node* result = NULL;
    node ** lastPtrRef = &result;

    while(1)
    {
        //special case: if list a runs out
        if(a == NULL)
        {
            //take the rest of b
            *lastPtrRef = b;
            break;
        }
        //special case: if list b runs out
        else if(b == NULL)
        {
            //take the rest of a
            *lastPtrRef = a;
        }
        else
        {
            MoveNode(lastPtrRef, &a);
            lastPtrRef = &((*lastPtrRef)->next);
            MoveNode(lastPtrRef, &b);
            lastPtrRef = &((*lastPtrRef)->next);
        }
    }

    return result;
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
    //create list a and list b
    node* a = BuildOneTwoThree();
    node* b = BuildNewNode(1);
    Push(&b, 13);
    Push(&b, 7);

    //print them
    printf("List a: ");
    PrintList(a);                   //1 2 3
    printf("List b: ");
    PrintList(b);                   //7 13 1

    printf("Shuffle merge...\n");
    //merging a and b, alternating nodes of a and b
    node* mergedList = ShuffleMerge(a, b);

    printf("Merged list: ");
    PrintList(mergedList);          //1 7 3 13 3 1

}


