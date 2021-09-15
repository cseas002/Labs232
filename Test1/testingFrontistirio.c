#include <stdio.h>

int main()
{
    if (0.2) // output is true but it shows a warning 
             //(implicit conversion from 'double' to '_Bool' changes value from 0.2 to true [-Wliteral-conversion])
        printf("%d\n", 1 + 3 * 2);
    for (int i = 0; i < 10; i++)
        printf("%d\n", i);

    int i = 0; // Needed for printf later, unless there is the error (1)

    printf("%d\n", i); // Error because i's scope is in for loop        ERROR (1)
                       // => Same as Java
}