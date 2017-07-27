#include <stdio.h>
#include <stdlib.h>
#include "DataStructuresFunction.h"

#define NUM_ELEM (sizeof (x) / sizeof(*(x)))

void copy_string(char *, char *);
void printArrAdd(int* arr, int n, int* p);
void func(int* arr, int n, int* p, int* buffer);

int main()
{
	//part 1
	int n = 20, *pntr;
	pntr = &n;
	printf("Address of n variable: %x\n", &n);
	printf("Address stored in pntr variable: %x\n", pntr);
	printf("Value of *pntr variable: %d\n", *pntr);

	//part 2
	char source[100], target[100], arr[100];
	char* arrP = &arr;
	printf("Enter source string\n");
	gets(source);
	copy_string(target, source);
	printf("Target string is \"%s\"\n", target);
	printf("Source string is \"%s\"\n", source);
	printf("Source memory address is \"%x\"\n", &source);
	printf("Target memory address is \"%x\"\n", &target);
	printf("\n");
	
	

	//part 3
	/*Demonstrate the use of pointers with arrays.Using a pointer to int,
	create and initialize an array of 8 integers.Print the base address of the
	array, Write a function that iterates over the array and prints the value and
	address of every element in a specific index, putting the size of the array into
	consideration. 
	
	Re-write your program and function, to iterate over the array based on the
	constant above that defines the array size. Within the function, create and
	return a new array that stores 4 values as follows; 1. address of the first
	element, 2. address of the last element, 3. distance apart (last, first), and 4.
	the product of all elements in the array.	*/
	int* pA;
	int arrC[8] = { 1,2,3,4,5,6,7,8 };
	pA = &arrC;
	printf("Base Address of array is: %x\n", &arrC);
	printArrAdd(arrC, 8, pA);

	//3b
	int* px;
	int x[] = { 1,2,3,4,5,6,7,8 };
	px = &x;
	printf("NUM_Elements: %d\n", NUM_ELEM);
	printArray(x,NUM_ELEM);
	int* buffer = malloc(NUM_ELEM);
	func(x, NUM_ELEM, px, buffer);
	printArray(buffer, 4);
	free(buffer);



	return 0;
}

void copy_string(char *target, char *source) {
	while (*source) {
		*target = *source;
		source++;
		target++;
	}
	*target = '\0';
}

void printArrAdd(int* arr, int n, int* p) {
	for (int i = 0; i < n; i++) {
		printf("Element Address: %x ", p);
		printf(" Element value: %i ", *p);
		printf("\n");
		p = p + 1;
	}
}

void func(int* arr, int n, int* p, int* buffer) {
	buffer[0] = p;
	p = p + 7;
	buffer[1] = p;
	buffer[2] = n - 1;
	int product = 1;
	p = p - 7;
	for (int i = 0; i < n; i++) {
		int val = *p;
		product = product * val;
		p = p + 1;
	}
	buffer[3] = product;
}
