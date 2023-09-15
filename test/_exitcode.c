#include "shell.h"

/**
 * _strncpy - Copies a string up to a specified length.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The maximum number of characters to be copied.
 *
 * Return: A pointer to the concatenated string.
 */


char *_strncpy(char *dest, char *src, int n)
{
	int k, l;
	char *s = dest;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < n)
	{
		l = k;
		while (l < n)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (s);/* Return the result*/
}

/**
 * _strncat - Concatenates two strings up to a specified length.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used.
 *
 * Return: A pointer to the concatenated string.
 */


char *_strncat(char *dest, char *src, int n)
{
	int k, l;
	char *s = dest;

	k = 0;
	l = 0;
	while (dest[k] != '\0')
		k++;
	while (src[l] != '\0' && l < n)
	{
		dest[k] = src[l];
		k++;
		l++;
	}
	if (l < n)
		dest[k] = '\0';
	return (s);/* return the result*/
}


/**
 * _strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the memory area in 's' where 'c' is found,
 *	or NULL if 'c' is not present.
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

