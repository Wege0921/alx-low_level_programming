#include "shell.h"
/**
 * get_history_file - Gets the path to the history file.
 * @info: Pointer to the parameter struct.
 *
 * Return: Allocated string containing the history file path.
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	/* Get the HOME directory from the environment variables */
	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	/* Allocate memory for the history file path */
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	/* Combine the HOME directory and history file name to create the path */
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - Writes the command history to a file.
 * @info: Pointer to the parameter struct.
 *
 * Return: 1 on success, -1 on failure.
 */

int write_history(info_t *info)
{
	ssize_t s;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);
	/* Open the history file for writing, creating it if necessary */
	s = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (s == -1)
		return (-1);
	/* Write each history entry to the history file */
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, s);
		_putfd('\n', s);
	}
	/* Flush any remaining characters to the file and close it */
	_putfd(BUF_FLUSH, s);
	close(s);
	return (1);
}

/**
 * read_history - Reads the command history from a file.
 * @info: Pointer to the parameter struct.
 *
 * Return: The number of history entries read, or 0 on failure.
 */
int read_history(info_t *info)
{
	int x, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);
	/* Open the history file for reading */
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	/* Get the file size and allocate memory for reading */
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (x = 0; x < fsize; x++)
		if (buf[x] == '\n')
		{
			buf[x] = 0;
			build_history_list(info, buf + last, linecount++);
			last = x + 1;
		}
	if (last != x)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}


/**
 * build_history_list - Adds an entry to the history linked list.
 * @info: Pointer to the parameter struct.
 * @buf: The history entry to add.
 * @linecount: The line count of the history entry.
 *
 * Return: Always 0.
 */

int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	/* Add the history entry to the linked list */
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - Renumbers the history linked list after changes.
 * @info: Pointer to the parameter struct.
 *
 * Return: The new history entry count (histcount).
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int x = 0;

	/* Renumber the history entries */
	while (node)
	{
		node->num = x++;
		node = node->next;
	}
	return (info->histcount = x);
}

