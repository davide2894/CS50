/*
    Stanford University - Computer Science - Linked list exercises

    Create a functions that counts the number of times a given int occurs in a list

*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*

    Function included in "list.h"

int Count(node* head, int elementToSearchFor)
{
    node* current = head;
    int count = 0;

    while(current != NULL)
    {
        if(current->data == elementToSearchFor)
        {
            count++;
            current = current->next;
        }
        else
            current = current->next; //advance to next node
    }

    return(count);
}

*/


int main(void)
{
    node* list = BuildOneTwoThree();    //build 1 2 3
    int count = Count(list, 2);
    printf("%i\n", count);              //returns 1 since 2 occuse
                                        //once in the list
}
