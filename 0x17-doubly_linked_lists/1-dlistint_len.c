#include "lists.h"

/**
 * dlistint_len - short description
 *
 * Description: long description
 *
 * @h: double linked list pointer
 *
 * Return: return description
 */
size_t dlistint_len(const dlistint_t *h)
{
	dlistint_t *current;
	size_t count;

	current = (dlistint_t *) h;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
