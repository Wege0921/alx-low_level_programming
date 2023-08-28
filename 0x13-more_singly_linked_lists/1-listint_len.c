#include <stddef.h>
#include "lists.h"

/**
 * listint_len - Returns the number of elements in a listint_t linked list.
 * @h: Pointer to the head of the linked list.
 *
 * Return: The number of elements in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0; /* Initialize the count of elements */

	while (h != NULL) /* Traverse the linked list */
	{
		h = h->next; /* Move to the next node */
		count++; /* Increment the count of elements */
	}

	return (count); /* Return the total number of elements */
}
