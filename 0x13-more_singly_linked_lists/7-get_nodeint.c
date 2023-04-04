#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - Returns the node at a given index in a linked list.
 * @head: A pointer to the first node of the list.
 * @index: The index of the node to be returned.
 *
 * Return: If the function fails or the node does not exist - NULL.
 *         Otherwise - a pointer to the requested node.
 **/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int counter = 0;

	if (head == NULL)
		return (NULL);

	while (head != NULL && counter < index)
	{
		head = head->next;
		counter++;
	}

	if (counter != index)
		return (NULL);

	return (head);
}

