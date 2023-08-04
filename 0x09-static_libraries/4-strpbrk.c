#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: The string to be searched.
 * @accept: The set of bytes to be matched.
 *
 * Return: A pointer to the byte in s that matches
 *	one of the bytes in accept,
 *	or null if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	char *match;

	while (*s)
	{
		for (match = accept; *match; match++)
		{
			if (*s == *match)
				return (s);
		}
		s++;
	}

	return ('\0');
}
