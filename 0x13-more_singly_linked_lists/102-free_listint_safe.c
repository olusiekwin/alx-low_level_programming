#include "lists.h"

/**
* free_listint_safe - frees a listint_t list safely
* @h: double pointer to head of list
*
* Return: size of list that was freed
*/
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *slow, *fast, *tmp;

	if (!h || !*h)
		return (count);

	slow = *h;
	fast = (*h)->next;

	while (fast && fast < slow)
	{
		tmp = slow;
		slow = slow->next;
		free(tmp);
		count++;

		tmp = fast;
		fast = fast->next;
		free(tmp);
		count++;

		if (fast)
			fast = fast->next;
	}

	/* free any remaining nodes */
	while (slow)
	{
		tmp = slow;
		slow = slow->next;
		free(tmp);
		count++;
	}

	/* set head to NULL */
	*h = NULL;

	return (count);
}

