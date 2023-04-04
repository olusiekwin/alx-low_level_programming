#include "lists.h"

/**
* print_listint_safe - Prints a listint_t linked list safely.
* @head: Pointer to the start of the list.
*
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *slow = head, *fast = head;

while (slow && fast && fast->next)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
fast = fast->next->next;
count++;

/* Check for a loop */
if (slow == fast)
{
printf("[%p] %d\n", (void *)slow, slow->n);
count++;

slow = head;
while (slow != fast)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
fast = fast->next;
count++;
}

printf("-> [%p] %d\n", (void *)slow, slow->n);
break;
}
}

/* Print the remaining nodes, if any */
while (slow)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
count++;
}

return (count);
}

