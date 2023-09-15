#include "shell.h"

/**
 * is_cmd - Checks if a file is an executable command.
 * @info: The info struct (not used in this function).
 * @path: The path to the file.
 *
 * Return: 1 if the file is an executable command, 0 otherwise.
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);/* Return */
}

/**
 * dup_chars - Duplicates characters from a string.
 * @pathstr: The source PATH string.
 * @start: The starting index to copy from.
 * @stop: The stopping index (exclusive) to copy until.
 *
 * Return: A pointer to a new buffer
 *	containing the duplicated characters.
 */


char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[y++] = pathstr[x];
	buf[y] = 0;
	return (buf);
}


/**
 * find_path - Finds the full path of a command within the PATH string.
 * @info: The info struct (not used in this function).
 * @pathstr: The PATH string to search within.
 * @cmd: The command to find.
 *
 * Return: A pointer to the full path of the command
 *	if found, or NULL if not found.
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			path = dup_chars(pathstr, curr_pos, x);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[x])
				break;
			curr_pos = x;
		}
		x++;
	}
	return (NULL);
}


