/*

    Stanford University - Computer Science - Linked List Exercises

    Write a RemoveDuplicates() function which takes a list sorted in increasing order and
    deletes any duplicate nodes from the list. Ideally, the list should only be traversed once
*/


/*

Functions used from list.h

void RemoveDuplicates(node* head)
{
    //get list length
    int len = Length(head);

    if(len == 1 || head == NULL)
    {
        printf("Nothing to remove\n");
    }

    node* current = head;

    //iterate until next node is not empty otherwise there would be nothing to compare to
    while(current->next != NULL)
    {
        //compare current and next node
        if(current->data == current->next->data)
        {
            node* nextNext = current->next->next;
            free(current->next);                    //delete duplicate node
            current->next = nextNext;               //skip deleted position
        }
        else
        {
            //if there is no deletion, advance to next node
            current = current->next;
        }
    }
}


void InsertNth(node** head, int index, int data)
{
    node* current = *head;

    if(index == 0)
        Push(head, data);
    else
    {
        for(int i = 0; i < index-1; i++)
        {
            current = current->next; //reach desired index position
        }
        Push(&(current->next), data); //push in front of the next node
                                      //i.e. at the desired index
    }
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
    node* head = BuildOneTwoThree();
    //at index 2 insert 3
    InsertNth(&head, 3, 3);
    //at index 3 insert 4
    InsertNth(&head, 4, 4);
    //at index 4 insert 7
    InsertNth(&head, 5, 7);

    printf("List: ");
    PrintList(head);            // 1 2 3 3 4 7

    printf("Deleting duplicates...\n");
    RemoveDuplicates(head);
    printf("Now list is: ");
    PrintList(head);            // 1 2 3 4 7

}
