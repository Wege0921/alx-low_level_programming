#include "main.h"

/**
 * _strstr - locates a substring in a string.
 * @haystack: The string to be searched.
 * @needle: The substring to be located.
 *
 * Return: A pointer to the beginning of the located substring, or
 *	 NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*n && *h == *n)
		{
			h++;
			n++;
		}

		if (!(*n))
			return (haystack);

		haystack++;
	}

	return ('\0');
}
