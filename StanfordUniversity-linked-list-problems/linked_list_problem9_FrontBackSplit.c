/*

    Stanford University - Computer Science - Linked List Exercises

    Given a list, split it into two sublists — one for the front half, and one for the back half.
    If the number of elements is odd, the extra element should go in the front list.
    So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7,11}.

*/


/*


Functions used from list.h

void FrontBackSplit(node* sourceList, node** frontRef, node** backRef)
{
    //get list length
    int len = Length(sourceList);
    printf("len = %i\n", len);

    //special case: list length is less than 2
    if(len < 2)
    {
        *frontRef = sourceList;     //front half becomes the sourceList
        *backRef = NULL;            //back half is empty
    }
    else
    {
        node* current = sourceList;
        int cutPoint = (len - 1) / 2;

        //reach cutting point
        for(int i = 0; i < cutPoint; i++)
        {
            current = current->next;
        }

        //now current is at the cutting point
        //cut list here
        *frontRef = sourceList;
        *backRef = current->next;
        current->next = NULL;
    }
}



void Push(node** headRef, int newData)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}



int Length(node* head)
{
    node* current = head;
    int count = 0;

    while(current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
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
*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void)
{
    //create source list
    node *sourceList = BuildNewNode(11);
    Push(&sourceList, 7);
    Push(&sourceList, 5);
    Push(&sourceList, 3);
    Push(&sourceList, 2);
    printf("Source list: ");
    PrintList(sourceList);      //Source list: 2 3 5 7 11

    //create front list
    node* frontRef = NULL;

    //create back half list
    node* backRef = NULL;

    //Split the list in two halves
    FrontBackSplit(sourceList, &frontRef, &backRef);
    printf("Front half: ");     //2 3 5
    PrintList(frontRef);
    printf("Back half: ");      //5 7 11
    PrintList(backRef);

}
