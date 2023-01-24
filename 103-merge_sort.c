#include "sort.h"

/**
 * printArr - prints array fro - to (exclusive)
 * @arr: array
 * @fro: initial index
 * @to: final index
*/
void printArr(int *arr, int fro, int to)
{
    for (; fro < to; fro++)
    {    
        printf("%d", arr[fro]);
        if (fro < to - 1)
            printf(", ");
    }
    printf("\n");
}
/**
 * copy - copies one array to another
 * @src: initial array
 * @lo: least index
 * @len: len
 * @dest: destination
 */
void copy(int *src, int lo, int len, int *dest)
{
    int k;

    for (k = lo; k < len; k++)
        dest[k] = src[k];
}
/**
 * merge - merges the array
 * @out: array to merge into
 * @lo: least index
 * @mid: mid point index
 * @hi: len
 * @arr: split array
*/
void merge(int *out, int lo, int mid, int hi, int *arr)
{
    int i = lo, j = mid, k;

    printf("Merging...\n");
    printf("[left]: ");
    printArr(arr, lo, mid);
    printf("[right]: ");
    printArr(arr,mid, hi);

    for (k = lo; k <= hi; k++)
    {
        if (i < mid && (j >= hi || arr[i] <= arr[j]))
        {
            out[k] = arr[i];
            i += 1;
        }
        else
        {
            out[k] = arr[j];
            j += 1;
        }
    }
    copy(out, 0, hi, arr);
    printf("[Done]: ");
    printArr(arr, lo, hi);
}

/**
 * split - uses top-down split
 * @arr: array to split
 * @lo: least index of array
 * @hi: len
 * @out: output array
*/
void split(int *arr, int lo, int hi, int *out)
{
    int mid;

    if (hi - lo <= 1)
        return;
    
    mid = (hi + lo) / 2;
    
    split(arr, lo, mid, out);
    split(arr, mid, hi, out);

    merge(out, lo, mid, hi, arr);
}
/**
 * merge_sort - sorts an array in asc using Merge sort
 * @array: pointer to array
 * @size: size of array
*/
void merge_sort(int *array, size_t size)
{
    int *out;

    out = malloc(sizeof(int) * size - 1);
    if (out == NULL)
        return;
    split(array, 0, (int) size, out);
    free(out);
}