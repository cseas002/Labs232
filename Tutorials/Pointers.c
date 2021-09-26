#include <stdio.h>

// * = VALUE
// & = POSITION

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int* p = NULL;
    int a = 10, b = 20;
    swap(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);
}