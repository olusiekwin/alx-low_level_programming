#include "lists.h"

/**
 * get_dnodeint_at_index - short description
 *
 * Description: long description
 *
 * @head: argument_1 description
 * @index: argument_2 description
 *
 * Return: return description
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int current_index = 0;
	dlistint_t *current;

	if (head == NULL)
		return (NULL);
	current = head;
	while (current)
	{
		if (current_index == index)
			return (current);
		current_index++;
		current = current->next;
	}
	return (NULL);
}
