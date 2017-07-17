#include <stdio.h>

int largestnumber(int x, int y);
int smallestnumber(int a, int b, int c);

int main(void)
{
	printf("Hello World\n");
	printf("\n");

	int x, y;

	int a, b, c;

	printf("This 1rst function will take in 2 intergers and return the largest\n");
	printf("Enter a number: ");
	scanf_s("%d", &x);
	printf("Enter a number: ");
	scanf_s("%d", &y);

	printf("Largest Number: %i\n", largestnumber(x, y));

	printf("This 2nd function will take in 3 intergers and return the smallest\n");
	printf("Enter a number: ");
	scanf_s("%d", &a);
	printf("Enter a number: ");
	scanf_s("%d", &b);
	printf("Enter a number: ");
	scanf_s("%d", &c);

	printf("Smallest Number: %i\n", smallestnumber(a, b, c));

	return 0;
}

int largestnumber(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

int smallestnumber(int a, int b, int c)
{
	if ((a < b) && (a < c))
		return a;
	if (b < c)
		return b;
	else
		return c;
}

