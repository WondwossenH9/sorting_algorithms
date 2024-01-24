#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - sorts subarray of integers
 * @subarr: subarray of an array of integers to sort
 * @buff: buffer to store the sorted subarray
 * @front: front index of the array
 * @mid: middle index of the array
 * @back: back index of the array
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, m = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; m++)
		buff[m] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[m++] = subarr[i];
	for (; j < back; j++)
		buff[m++] = subarr[j];
	for (i = front, m = 0; i < back; i++)
		subarr[i] = buff[m++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - does the merge sort algorithm through recursion
 * @subarr: subarray of an array of integers to sort
 * @buff: buffer to store the sorted result
 * @front: front index of subarray
 * @back: back index of subarray
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, middle);
		merge_sort_recursive(subarr, buff, middle, back);
		merge_subarr(subarr, buff, front, middle, back);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending
 *              order using the merge sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: does top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
