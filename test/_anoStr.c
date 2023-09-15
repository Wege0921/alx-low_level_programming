#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination.
 *
 * This function copies the characters from the source string
 *	to the destination
 * buffer, including the null-terminator. It ensures that the
 *	source and destination
 * are not the same and handles the case when the source is NULL.
 *
 * @dest: The destination buffer.
 * @src: The source string to copy.
 *
 * Return: A pointer to the destination buffer.
 */

char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	/* Ensure that the destination buffer is null-terminated. */
	dest[x] = 0;
	return (dest);
}


/**
 * _strdup - Duplicates a string.
 *
 * This function creates a duplicate of the input string `str` by allocating
 * memory for a new string and copying the characters from `str` to the new
 * string. It ensures that the input string is not NULL and handles memory
 * allocation failure.
 *
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */

char *_strdup(const char *str)
{
	int lstr = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lstr++;
	ret = malloc(sizeof(char) * (lstr + 1));
	if (!ret)
		return (NULL);
	/* Copy characters from the input string to the new string. */
	for (lstr++; lstr--;)
		ret[lstr] = *--str;
	return (ret);
}

/**
 * _puts - Prints a string to the standard output.
 *
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */

void _puts(char *str)
{
	int s = 0;

	if (!str)
		return;
	while (str[s] != '\0')
	{
		_putchar(str[s]);
		s++;
	}
}


/**
 * _putchar - Writes a character to the standard output.
 *
 * @c: The character to print.
 *
 * Return: On success, 1. On error, -1 is returned, and errno is set
 * appropriately.
 */

int _putchar(char c)
{
	static int z;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
		write(1, buf, z);
		z = 0;
	}
	if (c != BUF_FLUSH)
		buf[z++] = c;
	return (1);
}

