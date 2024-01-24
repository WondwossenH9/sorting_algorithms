#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - arranges a subset of an array of integers
 *                   according to the hoare partition scheme
 * @array: array of integers
 * @size: size of array
 * @left: starting index of the subset to arrange
 * @right: end index of the subset to arrange
 *
 * Return: final partition index
 *
 * Description: uses last element of the partition as the pivot
 * and print array after every swap of two elements
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int piv, top, below;

	piv = array[right];
	for (top = left - 1, below = right + 1; top < below;)
	{
		do {
			top++;
		} while (array[top] < piv);
		do {
			below--;
		} while (array[below] > piv);

		if (top < below)
		{
			swap_ints(array + top, array + below);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sort - applies quicksort algorithm via recursion
 * @array: array of integers to sort
 * @size: size of the array
 * @left: starting index of the array partition to arrange
 * @right: ending index of the array partition to arrange
 *
 * Description: uses Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, p - 1);
		hoare_sort(array, size, p, right);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending
 *                    order using the quicksort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: does the Hoare partition scheme and prints
 * the array after every swap of two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
