#include <stdio.h>
#include <cs50.h>




int main(void)
{
    int values[] = {1,3,5,6,7,8,9,11,22,44,55,785};
    printf("value: ");
    int value = get_int();

    for(int i=0; i<12; i++)
    {
        if(value == values[i])
        {
            printf("found number %i at position %i-->%i\n", value, i, values[i]);
            return true;
        }
    }
    printf("not found\n");
}

