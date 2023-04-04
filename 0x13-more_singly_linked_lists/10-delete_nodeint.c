#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes a node at a given position in a list.
 * @head: Address of the first node of a list.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 on success, -1 on failure.
 **/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev, *current;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
		return (1);
	}

	prev = *head;
	for (i = 0; i < index - 1 && prev != NULL; i++)
		prev = prev->next;

	if (prev == NULL || prev->next == NULL)
		return (-1);

	current = prev->next;
	prev->next = current->next;
	free(current);

	return (1);
}

