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
 * partition - lomuto partition scheme
 * @arr: Array to partition
 * @lo: lowest index of given array
 * @hi:  Highest index of array
 * 
 * Return: returns pivot point
*/
int partition(int *array, int lo, int hi, size_t size)
{
    int pivot, i, j;

    pivot = array[hi];/**last element*/

    for (i = lo - 1, j = lo; j < hi; j++)
    {
        if (array[j] <= pivot)
        {
            i += 1;
            swap((array + i), (array + j));
        }
    }
    i += 1;
    swap((array + i), (array + j));
    print_array(array, size);
    return (i);
}
/**
 * sort - inner implementation of the sorting algo
 * @arr: Pointer to array rto sort
 * @l: left most index
 * @r: right most index
*/
void sort(int *arr, int l, int r, size_t size)
{
    int pivot;

    if (l >= r || l < 0)
        return;
    
    pivot = partition(arr, l, r, size);
    sort(arr, l, pivot - 1, size);
    sort(arr, pivot + 1, r, size);

}
/**
 * quick_sort - sorts an array of integers in asc
 * order using the quick sort algo
 * @array: array
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
{
    if (size < 2 || array == NULL)
        return;
    sort(array, 0, size - 1, size);
}
