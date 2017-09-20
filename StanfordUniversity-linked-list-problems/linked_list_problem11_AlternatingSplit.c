/*
    Stanford University - Computer Science - Linked List - Exercises

    MoveNode() takes two lists, removes the front node from the second list and pushes
    it onto the front of the first

*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
    Functions used from list.h

void MoveNode(node** aRef,  node**bRef)
{
    node* toMove = *bRef;
    Push(aRef, toMove->data);

    *bRef = toMove->next;
    free(toMove);
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



void Push(node** headRef, int newData)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
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

int main(void)
{

    node* a = BuildOneTwoThree();
    node* b = BuildOneTwoThree();

    printf("List a: ");
    PrintList(a);           //1 2 3

    printf("List b: ");
    PrintList(b);           //1 2 3

    printf("Moving 1 from b to a...\n");
    MoveNode(&a, &b);

    printf("List a: ");
    PrintList(a);           //1 1 2 3

    printf("List b: ");
    PrintList(b);           //2 3


}
