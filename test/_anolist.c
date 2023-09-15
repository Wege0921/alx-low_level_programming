#include "shell.h"

/**
 * list_len - Determines the length of a linked list.
 * @h: Pointer to the first node.
 *
 * Return: The size of the list.
 */


size_t list_len(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		h = h->next;
		x++;
	}
	return (x);
}

/**
 * list_to_strings - Converts a linked list to an array of strings.
 * @head: Pointer to the first node.
 *
 * Return: An array of strings or NULL on failure.
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t x = list_len(head), y;
	char **strs;
	char *str;

	if (!head || !x)
		return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
		return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (y = 0; y < x; y++)
				free(strs[y]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}

/**
 * print_list - Prints all elements of a list_t linked list.
 * @h: Pointer to the first node.
 *
 * Return: The size of the list.
 */

size_t print_list(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++;
	}
	return (x);
}


/**
 * node_starts_with - Returns a node whose string starts with a prefix.
 * @node: Pointer to the list head.
 * @prefix: String to match at the beginning.
 * @c: The next character after the prefix to match.
 *
 * Return: The matching node or NULL.
 */


list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}


/**
 * get_node_index - Gets the index of a node in a linked list.
 * @head: Pointer to the list head.
 * @node: Pointer to the node.
 *
 * Return: The index of the node or -1 if not found.
 */


ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}

