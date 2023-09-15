#include "shell.h"

/**
 * interactive - Checks if the shell is in interactive mode.
 * @inf: A pointer to the info_t struct.
 *
 * Return: 1 if in interactive mode, 0 otherwise.
 */

int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - Checks if a character is a delimiter.
 * @c: The character to check.
 * @delimiter: The delimiter string to compare against.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */

int is_delim(char c, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Checks if a character is alphabetic.
 * @ch: The character to check.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts a string to an integer.
 * @str: The string to be converted.
 *
 * Return: The converted integer value or 0 if no numbers in the string.
 */

int _atoi(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
