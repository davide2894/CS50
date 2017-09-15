/*
    Stanford University - Computer Science - Linked list exercises

    Create a functions that counts the number of times a given int occurs in a list

*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"


void count(node* head, int key)
{
    //create node to track position in the list
    node* current = head;

    //create counter and set it to 0
    int count = 0;

    //traverse the list and search for key
    //and track how many times it is encountered in it
    while(current != NULL)
    {
        if(current->data == key)
        {
            count++;
            current = current->next;
        }
        else
        {
            current = current->next;
        }
    }
    printf("key %i is in the list %i times\n", key, count);
}


int main(void)
{
    node* head = malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;

    createList(head, 10);

    printList(head);

    count(head, 3);
}