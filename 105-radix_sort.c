#include "sort.h"

/**
 * sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void sort(int *array, size_t size, int sig, int *buff)
{
	int count[10];
	size_t i;

	for (i = 0; i < 10; i++)/**init*/
		count[i] = 0;
	for (i = 0; i < size; i++)/**count*/
		count[(array[i] / sig) % 10] += 1;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_short - sorts an array of int in asc using the
 * Radix sort
 * @array: array
 * @size: size of array
*/
void radix_sort(int *array, size_t size)
{
    
	int max, sig, *buff, i;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	for (max = array[0], i = 1; i < (int) size; i++)
		if (array[i] > max)
			max = array[i];
	
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}