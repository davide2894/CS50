/*
    Stanford University - Computer Science - Linked list exercises

    Create a GetNth function that takes a linked list
    and an integer index and returns the value
    stored in the node at that index position
*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*

    Function used from list.h

int GetNth(node* head, int index)
{
    node* current = head;
    int count = 0;
    int value = 0;

    while(current != NULL)
    {
        if(count == index)
        {
            value = current->data;
            break;
        }
        else
        {
            current = current->next;
            value++;
        }
    }
    return value;
}


*/


int main(void)
{
    node* myList = BuildOneTwoThree();      //Build 1 2 3
    int value = GetNth(myList, 2);          //Gets the value at index 2
                                            //of the list

    printf("%i\n", value);                  //which is 3
}
