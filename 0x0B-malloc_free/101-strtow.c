#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words in.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int i, words = 0, in_word = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (str[i] == ' ' && in_word)
		{
			in_word = 0;
		}
	}
	return (words);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to an array of strings (words), or NULL on failure.
 */
char **strtow(char *str)
{
	int i, j, k, words, len, start;
	char **result;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	words = count_words(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0, j = 0; i < words; i++)
	{
		while (str[j] == ' ')
			j++;
		start = j;
		while (str[j] != ' ' && str[j] != '\0')
			j++;
		len = j - start;
		result[i] = malloc(sizeof(char) * (len + 1));
		if (result[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(result[k]);
			free(result);
			return (NULL);
		}
		for (k = 0; k < len; k++, start++)
			result[i][k] = str[start];
		result[i][k] = '\0';
	}
	result[i] = NULL;
	return (result);
}
