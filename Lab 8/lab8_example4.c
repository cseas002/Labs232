#include <stdio.h>

int tempInt;
float tempFloat;


#define swap(a, b)	 if (a == (int) a && b == (int) b) {tempInt = a; a = b; b = tempInt;} else {tempFloat = a; a = b; b = tempFloat;}

int main()
{
	int a = 4, b = 5;
	swap(a, b);
	printf("%d %d\n", a, b);
	float c = 4.5, d = 5;
	swap(c, d);
	printf("%f %f\n", c, d);
}