/*

    Stanford University - Computer Science - Algorithm Exercises

    Write an Append() function that takes two lists, 'a' and 'b', appends 'b' onto the end of 'a',
    and then sets 'b' to NULL (since it is now trailing off the end of 'a')

*/


/*

Functions used from link.h

void Append(node** headRef_a, node** headRef_b)
{
    node* tail = *headRef_a;

    if(*headRef_a == NULL)
    {
        *headRef_a = *headRef_b;
    }
    else
    {
        //iterate down "a" list
        while(tail->next != NULL)
        {
            tail = tail->next;
        }

        //link a to b
        tail->next = *headRef_b;

        //b is now empty
        *headRef_b = NULL;
    }
}


void Push(node** headRef, int newData)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;

    newNode->next = *headRef; //correct: points the head in the heap
    *headRef = newNode; //correct: modify the head in the heap
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


*/



#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void)
{
    //create "a" list
    node* a = BuildOneTwoThree();

    //create "b" list
    node* b = BuildNewNode(6);
    Push(&b, 5);
    Push(&b, 4);

    printf("a list: ");
    PrintList(a);

    printf("b list: ");
    PrintList(b);

    Append(&a, &b);

    printf("a list after using Append(): ");
    PrintList(a);

    printf("b list after using Append(): ");
    PrintList(b);
}
