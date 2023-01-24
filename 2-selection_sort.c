#include "sort.h"

/**
 * swap - swaps two values at two addresses
 * r - address of right position
 * l - address of left position
*/
void swap(int *r, int *l)
{
    int temp;

    temp = *r;
    *r = *l;
    *l = temp;
}

/**
 * selection_sort - sorts an arrat in asc order
 * using Selection Sort
 * @array: array to be sorted
 * @size: size of array
*/
void selection_sort(int *array, size_t size)
{
    int i,j, min;

    for (i = 0; i < (int) size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < (int) size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
    
        if (min != i) 
        {
            swap(&(array[i]), &(array[min]));
            print_array(array, size);
        }
    }
}