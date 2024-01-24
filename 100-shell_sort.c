#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending
 *              order using the shell sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: Uses Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t step, i, j;

	if (array == NULL || size < 2)
		return;

	for (step = 1; step < (size / 3);)
		step = step * 3 + 1;

	for (; step >= 1; step /= 3)
	{
		for (i = step; i < size; i++)
		{
			j = i;
			while (j >= step && array[j - step] > array[j])
			{
				swap_ints(array + j, array + (j - step));
				j -= step;
			}
		}
		print_array(array, size);
	}
}
