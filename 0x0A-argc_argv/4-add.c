#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

/**
 * is_positive_number - Checks if a string is a positive number
 * @s: The string to check
 *
 * Return: 1 if the string is a positive number, 0 otherwise
 */
int is_positive_number(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (!isdigit(s[i]))
			return (0);
		i++;
	}

	return (1);
}

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 if successful, 1 if an error occurred
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (is_positive_number(argv[i]))
		{
			sum += atoi(argv[i]);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", sum);
	return (0);
}

