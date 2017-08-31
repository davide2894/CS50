#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int size = 6;
    int arr[] = {1,3,5,6,7,9,10};
    int start = 0;
    int middle = size/2;
    int target = 7;

    while(start<=size) //search as long as there is one element in the array
    {
        if(arr[middle]==target)
        {
            printf("target found: %i is %i\n", middle, target);
            return true;
        }
        else if(arr[middle]<target)
        {
            start = middle+1;
            middle = (start+size)/2;
            printf("middle now is %i\n", middle);
        }
        else if(arr[middle]>target)
        {
            //search left
            start = middle-1;
            size = size-1;
            middle = (start+size)/2;
            printf("middle now is %i\n", middle);
        }
    }
    printf("not found\n");
    return false; //in case the search fails



}