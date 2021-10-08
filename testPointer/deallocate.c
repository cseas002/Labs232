#include <stdio.h>
#include <stdlib.h>

void printSizeOf(char* a)
{
    printf("%lx\n", sizeof(a));
}

int main()
{
    char* a = malloc(40);
    printSizeOf(a);
    free(a);
    printf("%p\n", a);
    free(&a);

}