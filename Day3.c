#include <stdio.h>
#include "DataStructuresFunction.h"

long factorial(int X);
int binarySearchIterative(int A[], int n, int value);
int binarySearchRecursive(int A[], int value, int low, int high);
void merge(int L[], int R[], int A[], int l, int r);
void mergeSort(int A[]);


int main(void)
{
	int factorialtest = 6;
	printf("The factorial of %i is %i\n", factorialtest, factorial(factorialtest));
	printf("\n");

	int ArrayA[10] = {1,2,3,4,5,6,7,8,9,10 };
	int n = 10;
	int value = 3;
	int low = 0;
	int high = 9;
	printf("The value %i is located at index %i in the array\n", value, binarySearchIterative(ArrayA, n, value));
	printf("The value %i is located at index %i in the array\n", value, binarySearchRecursive(ArrayA, value, low, high));
	printf("\n");

	//merge sort
	int ArrayB[6] = { 23,100,92,4,123,89 };
	int ArrayC[6] = { 200,9,30,45,18,3 };
	int ArrayL[6];
	int ArrayR[6];
	int l = 6;
	int r = 6;
	printf("Sorted ArrayB is: ");
	printArray(ArrayB, 6);
	printf("\n");

	




	return 0;
}

long factorial(int X) // I have no idea why this works 
{
	if (X == 0)
		return 1;
	else
		return(X * factorial(X - 1));
}

int binarySearchIterative(int A[], int n, int value)
{
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] == value)
		{
			return mid;
		}
		else if (A[mid] >= value) 
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
}

int binarySearchRecursive(int A[], int value, int low, int high)
{
	if (high < low)
	{
		return low;
	}
	int mid = (low + high) / 2;
	if (A[mid] >= value)
	{
		return binarySearchRecursive(A, value, low, (mid - 1));
	}
	else
	{
		return binarySearchRecursive(A, value, (mid + 1), high);
	}

}

void merge(int L[], int R[], int A[], int l, int r)
{
	int i, j, k = 0;
	while (i < l && j < r)
	{
		if (L[i] < R[i])
		{
			A[k] = L[i];
			k = k + 1;
			j = j + 1;
		}
		else
		{
			A[k] = R[j];
			k = k + 1;
			j = j + 1;
		}
	}
}

void mergeSort(int A[])
{

}
