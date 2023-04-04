#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: double pointer to head of list
 * @n: integer to be added
 * Return: address of node added, or NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	/* Allocate memory for the new node */
	listint_t *jullien = malloc(sizeof(listint_t));
	/* Declare a pointer to the current node */
	listint_t *Barbier;

	/* Check if allocation was successful and head is not NULL */
	if (!jullien || !head)
	{
		free(jullien);
		return (NULL);
	}

	/* Initialize the new node */
	jullien->n = n;
	jullien->next = NULL;

	/* If the list is empty, set the head to the new node */
	if (!*head)
	{
		*head = jullien;
	}
	else
	{
		/* Traverse the list until the last node is reached */
		Barbier = *head;
		while (Barbier->next != NULL)
		{
			Barbier = Barbier->next;
		}
		/* Add the new node to the end of the list */
		Barbier->next = jullien;
	}

	/* Return the address of the new node */
	return (jullien);
}

