/*

    Stanford University - Computer Science - Linked List Exercises

    Write a function AlternatingSplit() that takes one list and divides up its nodes to make
    two smaller lists. The sublists should be made from alternating elements in the original
    list. So if the original list is {a, b, a, b, a}, then one sublist should be {a, a, a}
    and the other should be {b, b}.

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


void MoveNode(node** aRef,  node**bRef)
{
    node* toMove = *bRef;
    Push(aRef, toMove->data);

    *bRef = toMove->next;
    free(toMove);
}


void AlternatingSplit(node* source, node** aRef, node** bRef)
{
    node* a = NULL;
    node* b = NULL; //use these two sublists to split source list

    node* current = source;

    int len = Length(source);

    for(int i = 0; i < len; i++)
    {
        if(i % 2 == 0) //if index is even
            MoveNode(&a, &current);
        else
            MoveNode(&b, &current);
    }

    //aRef and bRef becomes respectively get a and b list
    *aRef = a;
    *bRef = b;
}

*/

int main(void)
{
    printf("Source list before split: ");
    node* sourceList = BuildOneTwoThree(); // 1 2 3
    PrintList(sourceList);

    node* aRef = NULL; //empty
    node* bRef = NULL; //empty

    printf("Applying alternate split...\n");
    AlternatingSplit(sourceList, &aRef, &bRef);

    printf("result list a: ");
    PrintList(aRef);

    printf("result list b: ");
    PrintList(bRef);
}
