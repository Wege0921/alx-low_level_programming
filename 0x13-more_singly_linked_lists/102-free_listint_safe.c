#include "lists.h"

/**
 * free_listint_safe - Safely frees a listint_t linked list.
 * @h: Double pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t list_size = 0; /* To store the size of the list */
	int diff; /* To calculate the difference between pointers */
	listint_t *temp; /* Temporary pointer to hold the next node */

	if (!h || !*h) /* Check if the list or head is NULL */
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next; /* Calculate the difference between pointers */
		if (diff > 0) /* If the difference is positive, no loop detected */
		{
			temp = (*h)->next; /* Store the next node in temp */
			free(*h); /* Free the current node */
			*h = temp; /* Move head to the next node */
			list_size++; /* Increment the list size */
		}
		else /* Loop detected or single node remaining */
		{
			free(*h); /* Free the current node */
			*h = NULL; /* Set head to NULL */
			list_size++; /* Increment the list size */
			break; /* Exit the loop */
		}
	}

	*h = NULL; /* Set head to NULL after freeing all nodes */

	return (list_size); /* Return the size of the freed list */
}

