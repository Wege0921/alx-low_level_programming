#include "shell.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: The string whose length is to be determined.
 *
 * Return: The integer length of the string.
 */

int _strlen(char *s)
{
	int sLen = 0;

	if (!s)
		return (0);

	while (*s++)
		sLen++;
	return (sLen);
}

/**
 * _strcmp - Compares two strings lexicographically.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}


/**
 * starts_with - Checks if a string starts with a given prefix.
 * @haystack: The string to search within.
 * @needle: The substring to find at the beginning of haystack.
 *
 * Return: Address of the next character after the prefix in haystack, or NULL.
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Concatenates two strings.
 *
 * @dest: The destination buffer.
 * @src: The source buffer to be appended.
 *
 * Return: A pointer to the destination buffer, containing the concatenated
 * strings.
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

