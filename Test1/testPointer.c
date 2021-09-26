#include <stdio.h>

int main()
{
    int i;
    int* p;
    p = &i;
    printf("%d", *p);
}