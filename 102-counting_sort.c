#include "sort.h"

/**
 * get_max - gets the max value in an array of integers
 * @array: array of integers
 * @size: size of array
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
 * counting_sort - sorts array of integers in ascending order
 *                 using the counting sort algorithm
 * @array: array of integers
 * @size: size of array
 *
 * Description: prints the counting array after it sets it up
 */
void counting_sort(int *array, size_t size)
{
	int *c, *s, maximum, i;

	if (array == NULL || size < 2)
		return;

	s = malloc(sizeof(int) * size);
	if (s == NULL)
		return;
	maximum = get_max(array, size);
	c = malloc(sizeof(int) * (maximum + 1));
	if (c == NULL)
	{
		free(s);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		c[i] = 0;
	for (i = 0; i < (int)size; i++)
		c[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		c[i] += c[i - 1];
	print_array(c, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		s[c[array[i]] - 1] = array[i];
		c[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = s[i];

	free(s);
	free(c);
}
