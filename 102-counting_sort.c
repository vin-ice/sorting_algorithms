#include "sort.h"

/**
 * counting_sort - sorts an array with the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, count, *c_arr, *out;
	/**
	 * 1. find the max value in input array
	 * 2. create an array of len(max+1): c_arr: init all ele to 0
	 * 3. accumulate c_arr ele
	 * 4. order input 
	*/
	for (max=array[0], count=0; count < (int)size; count++)
		if (array[count] > max)
			max = array[count];
	out = malloc(sizeof(int) * size);
	c_arr = malloc(sizeof(int) * max + 1);
	if (c_arr == NULL || out == NULL)
		return;
	for (count = 0; count <= max; count++) /**init*/
		c_arr[count] = 0;
	for (count = 0; count < (int)size; count++)/**count ele in input*/
		c_arr[array[count]] += 1;
	for (count = 1; count <= max; count++)/**accumulate ele*/
		c_arr[count] += c_arr[count - 1];
	print_array(c_arr, (size_t) max + 1);
	for (count = (int) size - 1; count >= 0; count--)/**order*/
	{	
		out[c_arr[array[count]] - 1] = array[count];
		c_arr[array[count]] -= 1;
	}
	for (count = 0; count <= (int) size - 1; count++)/**copy*/
		array[count] = out[count];
	free(c_arr);
	free(out);
}