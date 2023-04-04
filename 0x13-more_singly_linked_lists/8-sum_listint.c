#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data in a linked list.
 * @head: A pointer to the first node of the list.
 *
 * Return: The sum of all the data in the list.
 **/
int sum_listint(listint_t *head)
{
	int aggregate = 0;

	while (head != NULL)
	{
		aggregate += head->n;
		head = head->next;
	}

	return (aggregate);
}

