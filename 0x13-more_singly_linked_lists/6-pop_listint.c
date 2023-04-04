#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Delete the first element of a singly linked list.
 * @head: Pointer to a list.
 * Return: Integer if success.
 **/

int pop_listint(listint_t **head)
{
	listint_t *mia;
	int drake;

	if (*head == NULL)
		return (0);

	tp = *head;
	*head = mia->next;
	drake = mia->n;
	free(mia);
	return (drake);
}

