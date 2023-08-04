#include "main.h"

/**
 * _strchr - locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: A pointer to the first occurrence of
 * the character c in the string s,
 * or zero if the character is not found.
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (*s == c)
		return (s);

	return (0);
}
