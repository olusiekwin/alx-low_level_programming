/**
* reverse_listint - Reverses  listint_t linked list.
* @head: Double pointer to the head of the list.
*
* Return: Address of the new head of the reversed list.
*/
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next = NULL;

	if (!head || !(*head))
		return (*head);

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;

	return (*head);
}

