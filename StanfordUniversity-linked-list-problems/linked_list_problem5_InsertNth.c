/*
        Stanford University - Computer Science - Linked list exercises

        Write a function called InsertNth which can insert a new node
        at any index within a list.
        Given a list, an index 'n' in the range 0..length,
        and a data element, add a new node to the list so
        that it has the given index.

*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"


void InsertNth(node** head, int index, int data_to_insert)
{
        //point current to head
        node* current = *head;

        node* prevNode = current;

        //initialize position counter
        int count = -1;



        while(current)
        {
                //if goal index is head node but it is already occupied
                if(index == 0 && count == 0 && current != NULL)
                {
                        printf("position of index %i found!\n", index);

                        //create new node and set it to current position
                        node* new_node = malloc(sizeof(node));
                        new_node->data = data_to_insert;
                        new_node->next = *head;

                        //make new node the new head
                        *head = new_node;

                        //exit loop
                        break;
                }
                //if goal index is not head node and that positon is already occupied
                else if(count == index && count != 0 && index != 0 && current != NULL)
                {
                        //give new node current position and argument data
                        node* new_node = malloc(sizeof(node));
                        new_node->data = data_to_insert;

                        //link previous node to new node
                        prevNode->next = new_node;

                        new_node->next = current;

                        //move current to next node
                        current = current->next;

                        //exit loop
                        break;
                }
                //if goal index is last node
                else if(current == NULL)
                {
                        node* new_node = malloc(sizeof(node));
                        new_node->data = data_to_insert;
                        new_node->next = NULL;

                        current->next = new_node;
                }
                else
                {
                        //give previous node the current position
                        prevNode = current;

                        //move to the next node
                        current = current->next;

                        //update position counter
                        count++;

                }
        }

        //if index is greater than available indexes of the list
        if(index > count)
                printf("given index %i exceeds last linked list node at index %i\n", index, count);

}



int main(void)
{
        node* head = malloc(sizeof(node));
        head->data = 1;
        head->next = NULL;

        createList(head, 3);
        printList(head);

        InsertNth(&head, 3, 4);
        printList(head);
}