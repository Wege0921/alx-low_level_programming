#include <stddef.h>
#include <stdlib.h>
#include "lists.h"
/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Double pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			while (*h != slow)
			{
				temp = *h;
				*h = (*h)->next;
				free(temp);
				count++;
			}
			while (slow != NULL)
			{
				temp = slow;
				slow = slow->next;
				free(temp);
				count++;
			}
			*h = NULL;
			return (count);
		}
	}

	while (*h != NULL)
	{
		temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}

	return (count);
}
