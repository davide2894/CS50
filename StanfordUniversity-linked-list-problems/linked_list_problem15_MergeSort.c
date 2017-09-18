/*

    Stanford University - Computer Science - Linked List Exercises

    Write a classic recursive MergeSort(): split the list into two smaller lists,
    recursively sort those lists, and finally merge the two sorted lists together into a single
    sorted list.

*/


#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

int main(void)
{
    node* source = malloc(sizeof(node));
    node* a = malloc(sizeof(node));
    node* b = malloc(sizeof(node));

    source->data = 7;
    append(source, 9);
    append(source, 5);
    append(source, 16);
    append(source, 0);


    MergeSort(source, a, b);

    /*
        source list: 7 9 5 16 0
        A list: 7 9 5
        B list: 16 0

        A sorted list: 5 7 9
        B sortedlist: 0 16
        A merged with B list: 5 7 9 0 16
        Final merged and sorted list: 0 5 7 9 16

    */



}
