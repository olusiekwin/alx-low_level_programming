#include "lists.h"
#include <stdlib.h>

/**
* add_nodeint - Adds a new node at the beginning of a linked list.
* @head: Pointer to the head node of the linked list.
* @n: Value to be inserted into the new node.
* Return: Pointer to the new node.
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *c;

	c = malloc(sizeof(listint_t));
	if (c == NULL)
		return (NULL);

	c->n = n;
	c->next = *head;
	*head = c;
	return (*head);
}
