#include "lists.h"
/**
 * reverse_listint - reverses a listint_t linked list
 * @head: double pointer to head
 * Return: address of head of list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *nextDest = NULL, *tmpd = NULL, *curr = *head;

	if (!head || !(*head))
		return (*head);

	nextDest = curr->next;
	curr->next = NULL;

	while (next_dest)
	{
		tmpd = next_dest->next;
		nextDest->next = curr;
		curr = nextDest;
		nextDest = tmpd;
	}
	*head = curr;

	return (*head);
}

/*
*Drawing a chart and study this algo migh be helpfull
*
*/
