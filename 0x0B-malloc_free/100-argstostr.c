#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of a program.
 * @ac: Number of arguments.
 * @av: Array of arguments.
 *
 * Return: Pointer to concatenated string, or NULL if failure.
 */
char *argstostr(int ac, char **av)
{
	int i, j, total_length = 0, position = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			total_length++;
	}

	total_length += ac;

	str = malloc(sizeof(char) * (total_length + 1));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[position] = av[i][j];
			position++;
		}
		if (str[position] == '\0')
		{
			str[position++] = '\n';
		}
	}

	return (str);
}
