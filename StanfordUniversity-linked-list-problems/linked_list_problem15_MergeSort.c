/*

    Stanford University - Computer Science - Linked List Exercises

    Write a classic recursive MergeSort(): split the list into two smaller lists,
    recursively sort those lists, and finally merge the two sorted lists together into a single
    sorted list.

*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
    Functions used from "list.h"

void MergeSort(node** sourceList)
{
    node* head = *sourceList;
    node* a;
    node* b;

    FrontBackSplit(head, &a, &b);

    //recursively sort sublist a and b
    InsertSort(&a);
    InsertSort(&b);

    //Merge sublist a and b so that the are sorted together
    *sourceList = SortedMerge(a, b);
}


node* BuildNewNode(int data)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void Push(node** headRef, int newData)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
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

int main(void)
{
    //create source list
    node* sourceList = BuildNewNode(1);
    Push(&sourceList, 3);
    Push(&sourceList, 0);
    Push(&sourceList, 2);

    //print it
    printf("Source list: ");
    PrintList(sourceList);              // 2 0 3 1

    //apply MergeSort()
    printf("Using MergeSort()...\n");
    MergeSort(&sourceList);

    //print result list
    printf("Result sorted list: ");
    PrintList(sourceList);              //0 1 2 3
}
