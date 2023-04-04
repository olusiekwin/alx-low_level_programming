#include "list.h"
#include <stdlib.h>

/**
* add_nodeint_end - Adds a new node at the end of a list.
*
* @head: Address to the first node of in the list.
* @n: Integer being inserted into the new node.
*
* Return: Address towards the  new node.
**/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *temp;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
{
	*head = new_node;
	return (new_node);
}

	temp = *head;
	while (temp->next != NULL)
{
	temp = temp->next;
}

	temp->next = new_node;

	return (new_node);
}

