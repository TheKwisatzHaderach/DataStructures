#include <stdio.h>
#include "DataStructuresFunction.h"

int linearSearch(int A[], int v, int n);
void bubbleSort(int A[], int n);
int bubbleSortRecursive(int A[], int n);
void swap(int *xp, int *yp);
void quicksort(int *arr, int low, int high);

int main(void)
{
	// Linear Search
	int A[6] = { 3,2,4,1,5,6 };
	int v = 5;
	int n = 6;
	printf("The value %i is located at index %i in the Array\n", v, linearSearch(A, v, n));

	// Bubble Sort
	int B[6] = { 3,2,4,1,5,6 };
	int x = 6;
	printf("Unsorted Array: ");
	printArray(B, x);
	printf("Sorted Array: ");
	bubbleSort(B, x);
	printArray(B, x);

	int C[6] = { 3,2,4,1,5,6 };
	int c = 6;
	printf("bubbleSort using Recursion: \n");
	printf("Unsorted Array: ");
	printArray(C,c);
	printf("Sorted Array: ");
	bubbleSortRecursive(C,c);
	printArray(C,c);
	printf("\n");

	//quickSort
	int arr[] = { 6,2,3,1,9,10,15,13,12,17 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	printf("Unsorted Array: ");
	printArray(arr, arrSize);
	printf("Sorted Array: ");
	quicksort(arr, 0, arrSize - 1);
	printArray(arr, arrSize);


	return 0;
}

int bubbleSortRecursive(int A[], int n)
{
	if (n == 0)
		return;
	for (int x = 0; x < n - 1; x++)
		if (A[x] > A[x + 1])
			swap(&A[x], &A[x + 1]);
	return bubbleSortRecursive(A, n - 1);
}

void bubbleSort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++) 
		for (int j = 0; j < n - i - 1; j++)
			if (A[j] > A[j + 1])
				swap(&A[j], &A[j + 1]);
}


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int linearSearch(int A[], int v, int n)
{
	for (int x = 0; x < n; x++)
		if (A[x] == v)
			return x;
}

/** Divide  : Partition the array A[low....high] into two sub-arrays
*           A[low....j-1] and A[j+1...high] such that each element
*           of A[low....j-1] is less than or equal to A[j], which
*           in turn is is less than or equal to A[j+1...high]. Compute
*           the index j as part of this partitioning procedure.
* Conquer : Sort the two sub-arrays A[low....j-1] and A[j+1....high]
*           by recursive calls to quicksort
**/
void quicksort(int *arr, int low, int high)
{
	int pivot, i, j, temp;
	if (low < high) {
		pivot = low; // select a pivot element
		i = low;
		j = high;
		while (i < j) {
			// increment i till you get a number greater than the pivot element
			while (arr[i] <= arr[pivot] && i <= high)
				i++;
			// decrement j till you get a number less than the pivot element
			while (arr[j] > arr[pivot] && j >= low)
				j--;
			// if i < j swap the elements in locations i and j
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		// when i >= j it means the j-th position is the correct position
		// of the pivot element, hence swap the pivot element with the
		// element in the j-th position
		temp = arr[j];
		arr[j] = arr[pivot];
		arr[pivot] = temp;
		// Repeat quicksort for the two sub-arrays, one to the left of j
		// and one to the right of j
		quicksort(arr, low, j - 1);
		quicksort(arr, j + 1, high);
	}
}