#include <stdio.h>

int main()
{
    FILE* fp = NULL;

    fp = fopen("testingFile.txt", "w");

    for (int i = 0; i < 10; i++)
        fprintf(fp, "Line %d\n", i);

    fclose(fp);

}