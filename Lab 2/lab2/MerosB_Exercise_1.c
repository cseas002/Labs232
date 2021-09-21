#include <stdio.h>

void readNumbers(int arr[])
{
    FILE *fp = fopen("data.txt", "r");  
    for (int i = 0; i < 20; i++)
        fscanf(fp, "%d", &arr[i]);
    fclose(fp);
}

int largestNumber(int arr[])
{
    int max = arr[0];
    for (int i = 1; i < 20; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void printAll(int arr[], int max, char outputFile[])
{
    for (int i = 0; i < 20; i++)
        printf("%d\n", arr[i]);

    FILE *fp = fopen(outputFile, "w");
    fprintf(fp, "%d", max);
    fclose(fp);
}

int main()
{
    int arr[20];
    int largest;
    readNumbers(arr);
    largest = largestNumber(arr);
    printAll(arr, largest, "outputMerosBAskisi1");
}