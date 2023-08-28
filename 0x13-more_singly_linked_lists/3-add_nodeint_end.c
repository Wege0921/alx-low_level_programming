#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Double pointer to the head of the linked list.
 * @n: Value to be added in the new node.
 *
 * Return: The address of the new element (node), or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t)); /* Allocate memory */
	listint_t *current = *head; /* Create a pointer to traverse the list */

	if (new_node == NULL) /* Check if memory allocation fails */
		return (NULL);

	new_node->n = n; /* Assign the value to the new node */
	new_node->next = NULL; /* Set the next of the new node to NULL */

	if (*head == NULL) /* If the list is empty, make the new node the head */
	{
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to find the last node */
	while (current->next != NULL)
		current = current->next;

	current->next = new_node; /* Update the last node to the new node */

	return (new_node); /* Return the address of the new element (node) */
}

