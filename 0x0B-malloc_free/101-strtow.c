#include <stdlib.h>
#include <string.h>

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
	int i, j, k = 0, words, word_len;
	char **result;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = count_words(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < words; i++)
	{
		while (*str == ' ')
			str++;

		word_len = 0;
		while (str[word_len] != ' ' && str[word_len] != '\0')
			word_len++;

		result[i] = malloc(sizeof(char) * (word_len + 1));
		if (result[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(result[j]);
			free(result);
			return (NULL);
		}

		for (j = 0; j < word_len; j++)
			result[i][j] = str[k++];
		result[i][j] = '\0';

		str += word_len;
	}

	result[words] = NULL;
	return (result);
}

