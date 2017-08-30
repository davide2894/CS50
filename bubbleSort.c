#include <stdio.h>
#include <cs50.h>

void swap(int *a, int *b);

int main(void)
{
    int values[] = {3,5,2,1,4};
    int swap_counter = -1;

    printf("array: [%i,%i,%i,%i,%i]\n", values[0],values[1], values[2], values[3], values[4]);

    while(swap_counter != 0)
    {
        swap_counter = 0;
        printf("\n");
        printf("reset swap_counter to %i\n", swap_counter);

        for(int i=0; i<4; i++)
        {
            if(values[i]>values[i+1])
            {
                swap(&values[i], &values[i+1]);
                printf("pairing %i and %i\n", values[i], values[i+1]);
                printf("swapped %i for %i\n", values[i], values[i+1]);
                printf("array: [%i,%i,%i,%i,%i]\n", values[0],values[1], values[2], values[3], values[4]);
                swap_counter++;
                printf("swap_counter: %i\n", swap_counter);
            }
        }
    }
    printf("sorted array: [%i,%i,%i,%i,%i]\n", values[0],values[1], values[2], values[3], values[4]);
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

