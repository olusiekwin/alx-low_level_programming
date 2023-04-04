#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *temp = head, *loop_start = NULL;

	while (temp)
	{
		count++;
		printf("[%p] %d\n", (void *)temp, temp->n);
		temp = temp->next;
		if (temp >= loop_start)
		{
			printf("-> [%p] %d\n", (void *)temp, temp->n);
			exit(98);
		}
		if (!loop_start && temp)
			loop_start = temp;
	}

	return (count);
}
