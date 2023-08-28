#include <stddef.h>
#include "lists.h"
/**
 * find_listint_loop - Finds the start node of a loop in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The address of the node where the loop starts, or NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow); /* Address of the loop start node */
		}
	}

	return (NULL); /* No loop found */
}
