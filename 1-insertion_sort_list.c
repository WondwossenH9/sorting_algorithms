#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a listint_t doubly-linked list
 * @h: pointer to the head of the doubly-linked list
 * @n1: pointer to the first node to be swapped
 * @n2: second node to be swapped
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sort doubly linked list by insertion sort algorithm
 * @list: pointer to the head of a doubly-linked list of integers
 *
 * Description: prints the list after every swaps
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *input, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		input = i->prev;
		while (input != NULL && i->n < input->n)
		{
			swap_nodes(list, &input, i);
			print_list((const listint_t *)*list);
		}
	}
}
