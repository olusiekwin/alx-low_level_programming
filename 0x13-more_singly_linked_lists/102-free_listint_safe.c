#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _ra - reallocates memory for an array  pointer
 * to the nodes contained in a linked list.
 * @list: The old list being appended.
 * @size: Size of the new list always one more than the old list.
 * @new: New node  added to the list
 *
 * Return: Pointer to the new list
 */
listint_t **_ra(listint_t **list, size_t size, listint_t *new)
{
	listint_t **newSequence;
	size_t i;

	newSequence = malloc(size * sizeof(listint_t *));
	if (newSequence == NULL)
	{
		free(list);
		exit(98);
	}
	for (i = 0; i < size - 1; i++)
		newSequence[i] = list[i];
	newSequence[i] = new;
	free(list);
	return (newSequence);
}

/**
 * free_listint_safe - Frees  listint_t linked list.
 * @head: Double pointer to the start of the list.
 *
 * Return: Number of nodes present in the list.
 */
size_t free_listint_safe(listint_t **head)
{
	size_t i, my_num = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (my_num);
	while (*head != NULL)
	{
		for (i = 0; i < my_num; i++)
		{
			if (*head == list[i])
			{
				*head = NULL;
				free(list);
				return (my_num);
			}
		}
		my_num++;
		list = _ra(list, my_num, *head);
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(list);
	return (my_num);
}
