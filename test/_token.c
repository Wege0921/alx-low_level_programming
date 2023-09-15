#include "shell.h"

/**
 * strtow - Splits a string into words, ignoring repeat delimiters.
 *
 * This function takes an input string `str` and a delimiter string `d`, and
 * splits the input string into words based on the delimiter. It counts the
 * number of words, allocates memory for an array of strings, and copies each
 * word into the array.
 *
 * @str: The input string to be split.
 * @d:   The delimiter string to split the input.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */

char **strtow(char *str, char *d)
{
	int x, y, k, m, numwords = 0;
	char **s;

	/* Check if the input string is NULL or empty. */
	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (y = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[x], d))
			x++;
		k = 0;
		while (!is_delim(str[x + k], d) && str[x + k])
			k++;
		s[y] = malloc((k + 1) * sizeof(char));
		if (!s[y])
		{
			for (k = 0; k < y; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
	/* Copy the characters of the word into the array. */
		for (m = 0; m < k; m++)
			s[y][m] = str[x++];
		s[y][m] = 0;
	}
	s[y] = NULL;/* Null-terminate the array of strings. */
	return (s);
}


/**
 * strtow2 - Splits a string into words using a single delimiter character.
 *
 * This function takes an input string `str` and a delimiter character `d`, and
 * splits the input string into words based on the delimiter. It counts the
 * number of words, allocates memory for an array of strings, and copies each
 * word into the array.
 *
 * @str: The input string to be split.
 * @d:   The delimiter character to split the input.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */

char **strtow2(char *str, char d)
{
	int x, y, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	/* Count the number of words in the input string. */
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
				    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	/* Allocate memory for the array of strings. */
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		/* Skip leading delimiters. */
		while (str[x] == d && str[x] != d)
			x++;
		k = 0;
		while (str[x + k] != d && str[x + k] && str[x + k] != d)
			k++;
		s[y] = malloc((k + 1) * sizeof(char));
		if (!s[y])
		{
		/* Free previously allocated memory and return NULL on failure. */
			for (k = 0; k < y; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[y][m] = str[x++];
		s[y][m] = 0;/* Null-terminate the word. */
	}
	s[y] = NULL;
	return (s);
}

