#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* p = malloc(5);

    p = "test";
    *(p + 1) = 'r';
    printf("%s\n", p);
}