#include "sort.h"
#include <stdio.h>

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
 * bubble_sort - sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
    size_t n = size - 1;
    bool swapped;
    int idx;

    if (array == NULL)
        return;
    do/**passes*/
    {
        swapped = false;
        for (idx = 0; idx < (int) n; idx++)
        {
            if (*(array + idx) > *(array + idx + 1))
            {
                swap((array + idx), (array + idx + 1));
                print_array(array, size);
                swapped = true;
            }
        }

    } while(swapped);
}
