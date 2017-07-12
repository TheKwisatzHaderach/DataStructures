#include <stdio.h>

int largestnumber(int x, int y);

int main(void)
{
	printf("Hello World\n");
	printf("\n");
	
	int x;
	int y;

	printf("Enter a number: ");
	scanf_s("%d", &x);
	printf("Enter a number: ");
	scanf_s("%d", &y);

	printf("Largest Number: %i\n", largestnumber(x, y));

	return 0;
}

int largestnumber(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
