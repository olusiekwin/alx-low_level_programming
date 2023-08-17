#include "lists.h"

/**
 * print_dlistint - short description
 *
 * Description: long description
 *
 * @h: double linked list pointer
 *
 * Return: return description
 */
size_t print_dlistint(const dlistint_t *h)
{
	dlistint_t *current;
	size_t count;

	current = (dlistint_t *) h;
	count = 0;
	while (current)
	{
		count++;
		printf("%d\n", current->n);
		current = current->next;
	}
	return (count);
}
