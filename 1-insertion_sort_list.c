#include "sort.h"

/**
 * insertion_sort_list -> Write a function that sorts a doubly linked
 *list of integers in ascending order using the Insertion sort algorithm
 *
 *@list: It's a Doubly Linked List
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n;

	if (list == NULL || (*list)->next == NULL)
	{
		return;
	}

	n = (*list)->next;

	while (n)
	{
		while ((n->prev) && (n->prev->n > n->n))
		{
			n = swap_node(n, list);
			print_list(*list);
		}

		n = n->next;
	}
}

/**
 * swap_node -> It SWAPS 2 Nodes in a Doubly Linked List
 *@node: It's a Node
 *@list: The List of Node
 *Return: The Node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev = node->prev, *now = node;

	prev->next = now->next;

	if (now->next)
	{
		now->next->prev = prev;
	}

	now->next = prev;
	now->prev = prev->prev;
	prev->prev = now;

	if (now->prev)
	{
		now->prev->next = now;
	}

	else
	{
		*list = now;
	}

	return (now);

}
