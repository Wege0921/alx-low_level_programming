#include "lists.h" /* Include your lists.h file here */

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL; /* Pointer to the previous node */
	listint_t *next = NULL;     /* Pointer to the next node */

	while (*head) /* Loop until the current head becomes NULL */
	{
		next = (*head)->next; /* Store the next node */
		(*head)->next = previous;
		previous = *head; /* Move the previous pointer to the current node */
		*head = next; /* Move the head pointer to the next node */
	}

	*head = previous; /* Update the head pointer to point to the last node*/

	return (*head); /* Return the new head of the reversed list */
}

