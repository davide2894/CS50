#include <stdio.h>
#include <cs50.h>

//swap function declaration
void swap(int *a, int *b);

int main(void)
{
    int values[] = {3,5,2,1,4};
    int swap_counter = -1;

    while(swap_counter != 0) //the array is sorted when swap_counter is 0
    {
        //reset swap counter to 0
        swap_counter = 0;

        for(int i=0; i<4; i++)
        {
            if(values[i]>values[i+1])
            {
                //swap function call
                swap(&values[i], &values[i+1]);

                //increment swap_counter for each swap
                swap_counter++;
            }
        }
    }
    printf("sorted array: [%i,%i,%i,%i,%i]\n", values[0],values[1], values[2], values[3], values[4]);
}

//swap function definition
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

