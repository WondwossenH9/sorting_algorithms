#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - swaps two ints in an array
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
 * bitonic_merge - sorts a bitonic sequence inside an array of integers
 * @array: array of integers
 * @size: size of the array
 * @start: starting index of the sequence in array to sort
 * @seq: size of the sequence to sort
 * @flow: direction to sort in
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, skip = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + skip; i++)
		{
			if ((flow == UP && array[i] > array[i + skip]) ||
			    (flow == DOWN && array[i] < array[i + skip]))
				swap_ints(array + i, array + i + skip);
		}
		bitonic_merge(array, size, start, skip, flow);
		bitonic_merge(array, size, start + skip, skip, flow);
	}
}

/**
 * bitonic_seq - converts an array of ints into a bitonic sequence
 * @array: array of integers
 * @size: size of the array
 * @start: starting index of bitonic sequence
 * @seq: size of bitonic sequence.
 * @flow: direction to sort the bitonic sequence block
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t remove = seq / 2;
	char *s = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, s);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, remove, UP);
		bitonic_seq(array, size, start + remove, remove, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, s);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending
 *                order using the bitonic sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: prints the array after swap
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
