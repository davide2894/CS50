/*
        Stanford University - Computer Science - Linked list exercises

        Given a list sorted in increasing order, and a single node,
        write a SortedInsert() function that inserts the node into
        the correct sorted position in the list.
*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"


void SortedInsert(node** head, int new_data)
{
        //create node to track node we're currently pointing at
        node* current = *head;

        //create prevNode
        node* prevNode = current;

        //create new node and assign argument new data to it
        node* new_node = malloc(sizeof(node));
        new_node->data = new_data;


        while(current)
        {
                if(current->data == new_node->data && current != (*head))
                {
                        //point PrevNode to new_node
                        prevNode->next = new_node;

                        //point new node to current
                        new_node->next = current;

                        //move current to next position
                        current = current->next;

                        break;
                }
                else if( ( (*head)->data == new_node->data ) || ( new_node->data < (*head)->data ) )
                {
                        new_node->next = *head;

                        *head = new_node;

                        break;
                }
                //for example if last node is 3 and new node is 7
                else if(current->data < new_node->data && current->next == NULL )
                {
                        //link last node to new node
                        current->next = new_node;

                        //set new node as the last of the list
                        new_node->next = NULL;

                        break;
                }
                // if previous node < new node < next node (for example new node is 3 and  2 < 3 < 4)
                else if( ( current->data < new_node->data ) && ( new_node->data < current->next->data ) )
                {
                        prevNode = current;

                        //move current to next node
                        current = current->next;

                        //link new node to the next node
                        new_node->next = current;

                        //link previous node to new one
                        prevNode->next = new_node;

                        break;
                }
                else
                {
                        //update prevNode
                        prevNode = current;

                        //move current to next position
                        current = current->next;
                }
        }

}




int main(void)
{
        node* head = malloc(sizeof(node));
        head->data = 1;
        head->next = NULL;

        createList(head, 3);
        printList(head); // 1 2 3

        SortedInsert(&head, 0);

        SortedInsert(&head, 1);

        SortedInsert(&head, 2);

        SortedInsert(&head, 7);

        SortedInsert(&head, 4);

        SortedInsert(&head, 5);

        SortedInsert(&head, 6);

        SortedInsert(&head, 4);

        printList(head); //0 1 1 2 2 3 4 4 5 6 7

        return 0;
}