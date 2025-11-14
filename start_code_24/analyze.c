#include "analyze.h"
#include "algorithm.h"

#include <stdlib.h>
#include <time.h>

#define SIZE_ARRAY 512;

//
// Private
//
void fillarray(int *arr, int n, case_t c) 
{
    switch(c) 
    {
    case best_t:
        for(int i = 0; i < n; i++) 
        {
            arr[i] = i;
        }
        break;
    case worst_t:
        for(int i = 0;i < n; i++) 
        {
            arr[i] = n - i;
        }
        break;

    case average_t:
    default:
        for(int i = 0; i < n; i++) 
        {
            arr[i] = rand();
        }
        break;
    }
}
//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    int size = SIZE_ARRAY;
    srand(clock());
    
    for(int i = 0; i < n; i++) 
    {
        int arr[size];

        fillarray(arr, size, c);

        clock_t start = clock();

        switch(a)
        {
            case bubble_sort_t:
                bubble_sort(arr,size);
                break;

            case insertion_sort_t:
                insertion_sort(arr, size);
                break;

            case quick_sort_t:
                quick_sort(arr, size);
                break;
            
            case linear_search_t:
                linear_search(arr, n, size);
                break;

            case binary_search_t:
                binary_search(arr, n, size);
                break;
        }

        clock_t end = clock();

        buf[i].size = size;
        buf[i].time = (double)(end - start) / CLOCKS_PER_SEC;

        size *= 2;

    }
}