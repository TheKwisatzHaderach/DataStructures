#include <stdio.h>
#include<stdlib.h>
//#include "DataStructuresFunction.h"

int smallint(int A[], int n);
void insertionSort(int B[], int n);
void printArray(int Array[], int n);
void selectionSort(int Array[], int n);

int main(void)
{
	int Array[10] = { 323, 432, 4,321, 553, 2, 432, 342, 32, 10 };
	int n = 10;
	printf("smallestint: \n");
	printf("Array: ");
	printArray(Array, 10);
	printf("Smallest int from Array is: %i\n", smallint(Array, n));
	printf("\n");

	int ArrayA[6] = { 16,8,13,4,12,6 };
	int ArrayB[6] = { 7,9,7,10,8,6 };
	int x = 6;
	printf("insertionSort: \n");
	printf("Unsorted ArrayA: ");
	printArray(ArrayA, x);

	insertionSort(ArrayA,x);

	printf("Sorted ArrayA: ");
	printArray(ArrayA, x);
	printf("\n");

	printf("Unsorted ArrayB: ");
	printArray(ArrayB, x);

	insertionSort(ArrayB,x);

	printf("Sorted ArrayB: ");
	printArray(ArrayB, x);
	printf("\n");

	int ArrayC[6] = { 12,10,11,4,12,5 };
	int ArrayD[6] = { 7,2,23,12,12,21 };
	int y = 6;

	printf("selectionSort: \n");
	printf("Unsorted ArrayC: ");
	printArray(ArrayC, x);

	selectionSort(ArrayC, x);

	printf("Sorted ArrayC: ");
	printArray(ArrayC, x);
	printf("\n");

	printf("Unsorted ArrayD: ");
	printArray(ArrayD, x);

	selectionSort(ArrayD, x);

	printf("Sorted ArrayD: ");
	printArray(ArrayD, x);
	printf("\n");

}

int smallint(int A[], int n)
{
	int smallestint = A[0];
	for (int i = 0; i < n; i++)
	{
		if (A[i] < smallestint)
		{
			smallestint = A[i];
		}
	}
	return smallestint;
}

void insertionSort(int B[], int n)
{

	int j, key, i;
	for (j = 1; j < n; j++)
	{
		key = B[j];
		i = j - 1;

		while (i >= 0 && B[i] > key)
		{
			B[i + 1] = B[i];
			i = i - 1;
		}
		B[i + 1] = key;
	}
}

void printArray(int Array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%i ", Array[i]);
	}
	printf("\n");
}

void selectionSort(int Array[], int n)
{
	int holder;
	int smallest;
	for (int j = 0; j < (n - 1); j++)
	{
		smallest = j;
		for (int i = (j + 1); i < n; i++)
		{
			if (Array[i] < Array[smallest])
			{
				smallest = i;
			}
		}
		holder = Array[j];
		Array[j] = Array[smallest];
		Array[smallest] = holder;
	}
}
