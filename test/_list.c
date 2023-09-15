#include "shell.h"

/**
 * add_node - Adds a new node to the beginning of a linked list.
 * @head: Address of the pointer to the head node.
 * @str: String data for the new node.
 * @num: Node index used by history (optional).
 *
 * This function creates a new node with the specified string data and
 * optionally an index.
 *	It then adds this node to the beginning of the linked list.
 *
 * Return: Pointer to the newly created node.
 */



list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - Adds a new node to the end of a linked list.
 * @head: Address of the pointer to the head node.
 * @str: String data for the new node.
 * @num: Node index used by history (optional).
 *
 * This function creates a new node with the specified string data and
 * optionally an index.
 *	It then adds this node to the end of the linked list.
 *
 * Return: Pointer to the newly created node.
 */

list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - Prints only the 'str' element of a list_t linked list.
 * @h: Pointer to the first node of the linked list.
 *
 * This function traverses the linked list and prints
 *	the 'str' element of each node.
 *
 * Return: Size of the linked list.
 */

size_t print_list_str(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++;
	}
	return (x);
}

/**
 * delete_node_at_index - Deletes a node at the specified
 *	index in a linked list.
 * @head: Address of the pointer to the first node.
 * @index: Index of the node to delete.
 *
 * This function removes a node at the specified index in the linked list.
 *
 * Return: 1 on success, 0 on failure.
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int x = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (x == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		x++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - Frees all nodes of a linked list.
 * @head_ptr: Address of the pointer to the head node.
 *
 * This function deallocates memory for all nodes in the linked list.
 *
 * Return: void
 */


void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

