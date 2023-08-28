#include <stddef.h>
#include <stdlib.h>
#include "lists.h"
/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: Double pointer to the head of the linked list.
 * @n: Value to be added in the new node.
 *
 * Return: The address of the new element (node), or NULL if it fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t)); /* Allocate memory*/

	if (new_node == NULL) /* Check if memory allocation fails */
		return (NULL);

	new_node->n = n; /* Assign the value to the new node */
	new_node->next = *head; /* Set the next of the new node to the current head */

	*head = new_node; /* Update the head to point to the new node */

	return (new_node); /* Return the address of the new element (node) */
}
