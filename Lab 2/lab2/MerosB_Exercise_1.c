#include <stdio.h>
#define SIZE 20

void readNumbers(int* arr)
{
    FILE *fp = fopen("data.txt", "r");  
    for (int i = 0; i < SIZE; i++)
        fscanf(fp, "%d", &arr[i]);
    fclose(fp);
}

int largestNumber(int* arr)
{
    int max = arr[0];
    for (int i = 1; i < SIZE; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void printAll(int* arr, int max, char outputFile[])
{
    for (int i = 0; i < SIZE; i++)
        printf("%d\n", arr[i]);

    FILE *fp = fopen(outputFile, "w");
    fprintf(fp, "%d", max);
    fclose(fp);
}

int main()
{
    int arr[SIZE];
    int largest;
    readNumbers(arr);
    largest = largestNumber(arr);
    printAll(arr, largest, "outputMerosBAskisi1");
}