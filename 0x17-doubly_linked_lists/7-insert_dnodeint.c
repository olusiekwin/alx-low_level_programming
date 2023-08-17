#include "lists.h"

/**
 * insert_dnodeint_at_index - short description
 *
 * Description: long description
 *
 * @h: list head
 * @idx: argument_1 description
 * @n: argument_2 description
 *
 * Return: return description
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *previous, *new_node;
	unsigned int count = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));
	else if (*h == NULL && idx > 0)
		return (NULL);
	new_node = (dlistint_t *) malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	current = *h;
	previous = NULL;
	while (current)
	{
		if (count == idx)
		{
			previous->next = new_node;
			current->prev = new_node;
			new_node->prev = previous;
			new_node->next = current;
			return (new_node);
		}
		previous = current;
		current = current->next;
		count++;
	}
	free(new_node);
	if (count == idx)
		return (add_dnodeint_end(h, n));

	return (NULL);
}
