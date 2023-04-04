#include "lists.h"
#include <stdlib.h>

/**
* insert_nodeint_at_index - Inserts a new node at a given position.
* @head: A pointer to a pointer to the first node of the list.
* @index: The index where the new node should be inserted.
* @n: The value to be stored in the new node.
*
* Return: A pointer to the new node, or NULL on failure.
**/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
unsigned int i = 0;
listint_t *new_node, *temp;

if (head == NULL)
return (NULL);

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
if (index == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}

temp = *head;
while (i < index - 1 && temp != NULL)
{
temp = temp->next;
i++;
}
if (temp == NULL)
{
free(new_node);
return (NULL);
}
new_node->next = temp->next;
temp->next = new_node;

return (new_node);
}

