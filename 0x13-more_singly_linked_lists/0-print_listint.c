#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements of a listint_t linked list.
 * @h: A pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint(const listint_t *h)
{
	size_t node_counting = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		node_counting++;
	}

	return (node_counting);
}

