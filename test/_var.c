#include "shell.h"


/**
 * is_chain - Checks if the current character in the buffer
 *	is a command chaining delimiter.
 *
 * This function examines the character at the current
 *	position in the buffer (buf)to determine if it
 *	represents a command chaining delimiter
 *	such as "||", "&&", or ";". If a chaining delimiter
 *	is found, it updates the cmd_buf_type field in the
 *	info struct to indicate the type of chaining.
 *
 * @info: The parameter struct that stores information about the shell.
 * @buf: The character buffer containing the command line.
 * @p: Address of the current position in the buffer.
 *
 * Return: 1 if a command chaining delimiter is found, 0 otherwise.
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t y = *p;

	/* Check for "||" (logical OR) chaining delimiter. */
	if (buf[y] == '|' && buf[y + 1] == '|')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_OR;
	}
	/* Check for "&&" (logical AND) chaining delimiter. */
	else if (buf[y] == '&' && buf[y + 1] == '&')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_AND;
	}
	/* Check for ";" (sequential) chaining delimiter. */
	else if (buf[y] == ';')
	{
		buf[y] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);/* No chaining delimiter found. */
	*p = y;/* Update the current position in the buffer. */
	return (1);/* Chaining delimiter was found. */
}

/**
 * check_chain - Checks whether command chaining should
 *	continue based on the last command's status.
 *
 * This function examines the last command's status stored in the
 *	'info' struct and determines whether command chaining
 *	should continue. It adjusts the current position in the character buffer
 *	(buf) and sets the appropriate conditions to continue or terminate
 *	the chaining based on th chaining type (CMD_AND or CMD_OR).
 *
 * @info: The parameter struct that stores information about the shell.
 * @buf: The character buffer containing the command line.
 * @p: Address of the current position in the buffer.
 * @i: The starting position in the buffer.
 * @len: The length of the buffer.
 *
 * Return: Void.
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t y = *p;

	/* Check if the command chaining type is CMD_AND. */
	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			y = len;
		}
	}
	/* Check if the command chaining type is CMD_OR. */
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			y = len;
		}
	}

	*p = y;/* Update the current position in the buffer. */
}


/**
 * replace_alias - Replaces an alias in the tokenized string
 *	with its expanded value.
 *
 * This function searches for an alias defined in the shell's
 *	alias list that matches the beginning of the current command.
 *	If a matching alias is found, it replaces the command with
 *	its expanded value.
 *
 * @info: The parameter struct that stores information about the shell.
 *
 * Return: 1 if the alias was replaced, 0 otherwise.
 */

int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *p;

	/* Loop through 10 iterations to avoid infinite loops. */
	for (x = 0; x < 10; x++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	/* Return 1 to indicate that an alias was replaced. */
	return (1);
}

/**
 * replace_vars - Replaces variables in the tokenized string with their values.
 *
 * This function scans the command tokens for variables starting with '$' and
 * replaces them with their corresponding values if found in the environment.
 * It supports the special variables "$?" (exit status) and "$$" (process ID).
 *
 * @info: The parameter struct that stores information about the shell.
 *
 * Return: 1 if variables were replaced, 0 otherwise.
 */


int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
			continue;
		if (!_strcmp(info->argv[x], "$?"))
		{
			/* Replace with the exit status converted to a string. */
			replace_string(&(info->argv[x]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[x], "$$"))
		{
			replace_string(&(info->argv[x]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_string(&(info->argv[x]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		/* Replace with an empty string if the variable is not found. */
		replace_string(&info->argv[x], _strdup(""));

	}
	return (0);/* Return 1 to indicate that variables were replaced. */
}

/**
 * replace_string - Replaces a string with a new one.
 *
 * This function takes the address of an old string pointer and replaces it
 * with a new string. It also frees the memory occupied by the old string.
 *
 * @old: Address of the old string pointer.
 * @new: New string to replace the old one.
 *
 * Return: 1 if the replacement is successful, 0 otherwise.
 */

int replace_string(char **old, char *new)
{
	/* Free the memory occupied by the old string. */
	free(*old);
	/* Replace the old string pointer with the new string. */
	*old = new;
	/* Return 1 to indicate a successful replacement. */
	return (1);
}

