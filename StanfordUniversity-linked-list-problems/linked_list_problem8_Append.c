/*

    Stanford University - Computer Science - Algorithm Exercises

    Write an Append() function that takes two lists, 'a' and 'b', appends 'b' onto the end of 'a',
    and then sets 'b' to NULL (since it is now trailing off the end of 'a')

*/




#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

int main(void)
{
    node* headA = NULL;
    printf("A ");
    printList(headA);               // A list:

    node* headB = malloc(sizeof(node));
    headB->data = 4;
    headB->next = NULL;
    append(headB, 5);
    append(headB, 6);
    printf("B ");
    printList(headB);               // B list: 4 5 6



    AppendTwoLists(&headA, &headB); // A list 4 5 6
                                    // B list:

}

