#include "main.h"
#include <stddef.h>
/**
 * is_palindrome - Check if a string is a palindrome.
 * @s: The input string to check.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int len = 0;
	int i, j;

	if (s == NULL)
		return (0);

	while (s[len] != '\0')
		len++;

	for (i = 0, j = len - 1; i < len / 2; i++, j--)
	{
		if (s[i] != s[j])
			return (0);
	}

	return (1);
}
