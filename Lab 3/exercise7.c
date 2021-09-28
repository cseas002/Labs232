#include <stdio.h>
#define MAXSIZE 200

void readArray(int arr[], int* size)
{
	int* p = NULL;
	printf("Give the size of the array (from 1-10): ");
	scanf("%d", size);
	printf("Give the numbers: ");
	for (p = arr; p < arr + *size; p++)
		scanf("%d", p);
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void reverseArray(int arr[], int size)
{
	int* p = NULL;
	
	for (p = arr; p < arr + (size / 2); p++)
		swap(p, arr + size - 1 - (p - arr));
}

void printArray(int arr[], int size)
{
	printf("The reverse array is: \n");
	int *p;
	for (p = arr; p < arr + size; p++)
		printf("%d ", *p);
	printf("\n");
}


int main()
{
	int arr[MAXSIZE];
	int size, i;
	readArray(arr, &size);
	reverseArray(arr, size);
	printArray(arr, size);
}