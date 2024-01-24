#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - gets maximum value in an array of integers
 * @array: array of integers
 * @size: size of the array
 *
 * Return: maximum integer in the array
 */
int get_max(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}

/**
 * radix_counting_sort - sorts significant digits of an array of integers
 *                       in ascending order via the counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 * @sig: digit to sort
 * @buff: buffer to store the sorted array
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		arr[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		arr[i] += arr[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[arr[(array[i] / sig) % 10] - 1] = array[i];
		arr[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - sorts an array of integers in ascending
 *              order via radix sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: applies the LSD radix sort algorithm and prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maximum = get_maximum(array, size);
	for (sig = 1; maximum / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
