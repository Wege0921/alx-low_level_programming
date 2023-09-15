#include "shell.h"

/**
 * _myenv - Prints the current environment.
 * @info: Pointer to the info_t struct.
 *
 * Return: Always 0.
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @info: Pointer to the info_t struct.
 * @nofe: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */

char *_getenv(info_t *info, const char *nofe)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, nofe);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}


/**
 * _mysetenv - Initializes a new environment variable
 *	or modifies an existing one.
 * @info: Pointer to the info_t struct.
 *
 * Return: Always 0.
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs(" Incorrect number of arguements.\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Removes an environment variable.
 * @info: Pointer to the info_t struct.
 *
 * Return: Always 0.
 */


int _myunsetenv(info_t *info)
{
	int k;

	if (info->argc == 1)
	{
		_eputs(" Too few arguements.\n");
		return (1);
	}
	for (k = 1; k <= info->argc; k++)
		_unsetenv(info, info->argv[k]);

	return (0);
}


/**
 * populate_env_list - Populates the environment linked list
 *	from 'env'.
 * @info: Pointer to the info_t struct.
 *
 * Return: Always 0.
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		add_node_end(&node, environ[k], 0);
	info->env = node;
	return (0);
}


