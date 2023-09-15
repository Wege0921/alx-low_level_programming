#include "shell.h"

/**
 * _myhistory - Displays the history list, one command per line, preceded
 *              with line numbers, starting at 0.
 * @inf: Pointer to the info_t struct.
 *
 * Return: Always 0.
 */

int _myhistory(info_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * unset_alias - Unsets an alias identified by a string.
 * @inf: Pointer to the info_t struct.
 * @str: The string alias to unset.
 *
 * Return: Always 0 on success, 1 on error.
 */

int unset_alias(info_t *inf, char *str)
{
	char *p, c;
	int x;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	x = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, str, -1)));
	*p = c;
	return (x);
}


/**
 * set_alias - Sets an alias to a string.
 * @info: Pointer to the info_t struct.
 * @str: The string alias to set.
 *
 * Return: Always 0 on success, 1 on error.
 */


int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints an alias string.
 * @node: The alias node to print.
 *
 * Return: Always 0 on success, 1 on error.
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - Mimics the alias builtin (man alias).
 * @info: Pointer to the info_t struct.
 *
 * Return: Always 0.
 */

int _myalias(info_t *info)
{
	int x = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		p = _strchr(info->argv[x], '=');
		if (p)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}

