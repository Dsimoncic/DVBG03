#include "algorithm.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//
// Private
//

//
// Public
//
void bubble_sort(int *a, int n) 
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1; j++) 
		{
			if(a[j] > a[j + 1]) 
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void insertion_sort(int *a, int n)
{
	for(int i = 1; i < n; i++) 
	{
		int value = a[i];
		int j = i - 1;

		while(j >= 0 && a[j] > value) 
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = value;
	}
	// TODO: insertion sort
}

int compare(const void *x, const void *y)
{
	int a = *(const int *)x;
	int b = *(const int *)y;

	if(a < b) return -1;
	if(a > b) return 1;
	return 0;
}

void quick_sort(int *a, int n)
{
	qsort(a, (size_t)n, sizeof(int), compare);
	// TODO: quick sort
}

bool linear_search(const int *a, int n, int v)
{
	return false; // TODO: linear search
}

bool binary_search(const int *a, int n, int v)
{
	return false; // TODO: binary search
}
