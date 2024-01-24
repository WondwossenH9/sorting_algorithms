#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - arranges subset of array of integers according to
 *                    lomuto partition scheme
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of subset to arrange
 * @right: ending index of the subset to arrange
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, top, below;

	pivot = array + right;
	for (top = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (top < below)
			{
				swap_ints(array + below, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_ints(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - quicksorts algorithm via recursion
 * @array: array of integers to sort
 * @size: size of the array.
 * @left: starting index of array partition to arrange
 * @right: ending index of array partition to arrange
 *
 * Description: apply the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition - 1);
		lomuto_sort(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 *              order using quicksort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: Apply the Lomuto partition scheme and prints
 *              the array after each swapping two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
