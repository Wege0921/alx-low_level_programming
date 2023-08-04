#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: The string to be checked.
 * @accept: The characters to be considered for the prefix subtr
 *
 * Return: The number of bytes in the initial
 *	segment of s which consist only
 *	of bytes from accept.
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	while (*s && _strchr(accept, *s))
	{
		count++;
		s++;
	}

	return (count);
}

/**
 * _strchr - locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: A pointer to the first occurrence of the
 *	character c in the string s,
 *	or NULL if the character is not found.
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
