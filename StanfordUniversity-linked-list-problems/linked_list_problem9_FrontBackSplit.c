/*

    Stanford University - Computer Science - Linked List Exercises

    Given a list, split it into two sublists — one for the front half, and one for the back half.
    If the number of elements is odd, the extra element should go in the front list.
    So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7,11}.

*/




#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

int main(void)
{
    //create list with 1 node, split it
    node* head0 = malloc(sizeof(node));
    head0->data = 2;
    head0->next = NULL;
    append(head0, 3);
    append(head0, 5);
    append(head0, 7);
    append(head0, 11);
    FrontBackSplit(head0);                       // A list: 2 3 5 | B list: 7 11



    //create list with 1 node, split it
    node* head1 = malloc(sizeof(node));
    head1->data = 1;
    head1->next = NULL;
    createList(head1, 1);
    FrontBackSplit(head1);                       //splt not possible: only one node is in the list


    //create list with 2 nodes, split it
    node* head2 = malloc(sizeof(node));
    head2->data = 1;
    head2->next = NULL;
    createList(head2, 2);
    FrontBackSplit(head2);                      // A list: 1 | B list: 2


    //create list with 3 nodes, split it
    node* head3 = malloc(sizeof(node));
    head3->data = 1;
    head3->next = NULL;
    createList(head3, 3);
    FrontBackSplit(head3);                      // A list: 1 2 | B list: 3


    //create list with 4 nodes, split it
    node* head4 = malloc(sizeof(node));
    head4->data = 1;
    head4->next = NULL;
    createList(head4, 4);
    FrontBackSplit(head4);                      // A list: 1 2 3 | B list: 4
}
