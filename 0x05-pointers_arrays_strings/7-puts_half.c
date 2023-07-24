#include <stdio.h>
#include "main.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: Pointer to the string.
 *
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * puts_half - Prints the second half of a string, followed by a new line.
 * @str: Pointer to the string to be printed.
 *
 * Return: void.
 */
void puts_half(char *str)
{
	int length = _strlen(str);
	int start_index;

	if (length % 2 == 0)
		start_index = length / 2;
	else
		start_index = (length - 1) / 2 + 1;

	while (str[start_index] != '\0')
	{
		putchar(str[start_index]);
		start_index++;
	}

	putchar('\n');
}
