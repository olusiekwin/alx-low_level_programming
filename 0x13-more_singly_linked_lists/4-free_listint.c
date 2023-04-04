#include "lists.h"
#include <stdlib.h>

/**
* free_listint - Frees a list.
* @head: Address of the first node of a list.
**/
void free_listint(listint_t *head)
{
listint_t *current = head, *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
}

