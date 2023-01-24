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
 * sift_down - sifts the new first element to its 
 * appropriate index in the heap
 * @arr: array
 * @lo: starting index/position
 * @hi: last index
 * @size: size of array
*/
void sift_down(int *arr, int lo, int hi, size_t size)
{
    int root, child, sw;

    for (root = lo; root <= hi;)
    {
        child = root;
        sw = root;

        if (arr[sw] < arr[child])
            sw = child;
        if (child + 1 <= hi && arr[sw] < arr[child + 1])
            sw = child + 1;
        if (sw == root)
            return;
        else
        {
            swap((arr + root), (arr + sw));
            print_array(arr, size);
            root = sw;
        }
    }
}
/**
 * heapify - puts elements of arrat in a heap
 * @arr: array
 * @size: size of array
*/
void heapify(int *arr, size_t size)
{
    int start;

    for (start = (int) size - 1; start >= 0; start--)
        sift_down(arr, start, (int)size - 1, size);
}
/**
 * heap_sort - sorts an array of integers in asc
 * using Heap sort
 * @array: pointer to array
 * @size: size of array
*/
void heap_sort(int *array, size_t size)
{
    int end;

    heapify(array, size);/**build heap*/
    
    for (end = (int) size - 1; end > 0;)
    {
        swap((array + end), (array + 0));
        end -= 1;
        sift_down(array, 0, end, size);
    }
}