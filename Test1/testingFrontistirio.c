#include <stdio.h>
#include <stdbool.h>

void g(void)
{
    int i = 2;
    if (i > 0)
    {
        int i;
        i = 3;
    }
    printf("\n%d\n", i);
}

int main()
{
    if (0.2) // output is true but it shows a warning 
             // (implicit conversion from 'double' to '_Bool' changes value from 0.2 to true [-Wliteral-conversion])
        printf("%d\n", 1 + 3 * 2);
    for (int i = 0; i < 10; i++)
    {
        staticTest:
        printf("%d\n", i);
    }

    // int i = 0; // Needed for printf later, unless there is the error (1)

    // printf("%d\n", i); // Error because i's scope is in for loop        ERROR (1)
    //                    // => Same as Java
    // goto staticTest; // printing 0 instead of error (int i should be deleted)
    g();
    bool test = false;
    if (test)
        printf("OK");
}