#include <stdio.h>

void swap(int *p, int *q)
{
    int temp = *q;
    *q = *p;
    *p = temp;
}

void main()
{
    int x = 10;
    int y = 20;
    printf("x = %d, y= %d\n", x, y);
    swap(&x, &y);
    printf("x = %d, y= %d", x, y);
}

