#include "algorithm.h"
#include <stdio.h>
#include <stdbool.h>

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
	// TODO: bubble sort
}

void insertion_sort(int *a, int n)
{
	// TODO: insertion sort
}

void quick_sort(int *a, int n)
{
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
