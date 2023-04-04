#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - Frees a linked list.
 * @head: A pointer to the first node of the list.
 **/
void free_listint2(listint_t **head)
{
	listint_t *current_node;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		current_node = (*head)->next;
		free(*head);
		*head = current_node;
	}
}

