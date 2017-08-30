#include <stdio.h>
#include <cs50.h>

void swap(int* a, int* b);

int main(void)
{
   int x = 0;
   int y = 2;

   printf("x is %i\n", x);
   printf("y is %i\n", y);
   printf("swapping...\n");

   swap(&x, &y);
   printf("now x is %i\n", x);
   printf("now y is %i\n", y);

}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}