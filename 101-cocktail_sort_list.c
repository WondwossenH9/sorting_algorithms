#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - swaps a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it
 * @list: pointer to the head of a doubly-linked list of integers
 * @tail: pointer to the tail of the doubly-linked list
 * @shaker: pointer to the current swapping node of the cocktail shaker
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - swaps a node in a listint_t doubly-linked
 *                    list of integers with the node behind it
 * @list: pointer to the head of a doubly-linked list of integers
 * @tail: pointer to the tail of the doubly-linked list
 * @shaker: pointer to the current swapping node of the cocktail shaker
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - sorts a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm
 * @list: pointer to the head of a listint_t doubly-linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *cocktail;
	bool mixed = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (mixed == false)
	{
		mixed = true;
		for (cocktail = *list; cocktail != tail; cocktail = cocktail->next)
		{
			if (cocktail->n > cocktail->next->n)
			{
				swap_node_ahead(list, &tail, &cocktail);
				print_list((const listint_t *)*list);
				mixed = false;
			}
		}
		for (cocktail = cocktail->prev; cocktail != *list;
				cocktail = cocktail->prev)
		{
			if (cocktail->n < cocktail->prev->n)
			{
				swap_node_behind(list, &tail, &cocktail);
				print_list((const listint_t *)*list);
				mixed = false;
			}
		}
	}
}
