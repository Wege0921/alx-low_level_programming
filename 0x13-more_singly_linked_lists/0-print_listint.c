#include <stdio.h>
#include "lists.h"
/**
 * print_listint - Prints all elements of a listint_t linked list.
 * @h: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0; /* Initialize the count of nodes */

	while (h != NULL) /* Traverse the linked list */
	{
		printf("%d\n", h->n); /* Print the value of the current node */
		h = h->next; /* Move to the next node */
		count++; /* Increment the count of nodes */
	}
	return (count); /* Return the total number of nodes */
}

