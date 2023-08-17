#include "lists.h"

/**
 * sum_dlistint - short description
 *
 * Description: long description
 *
 * @head: argument_1 description
 *
 * Return: return description
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum = 0;

	if (head == NULL)
		return (sum);
	current = head;
	while (current)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
