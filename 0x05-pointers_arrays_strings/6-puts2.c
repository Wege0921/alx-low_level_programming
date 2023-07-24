#include <stdio.h>
#include "main.h"
/**
 * puts2 - Prints every other character of a string.
 * @str: Pointer to the string to be printed.
 *
 * Return: void.
 */


void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i % 2 == 0)

		{
			_putchar(str[i]);
		}
		else
			continue;
	}

	_putchar('\n');
}
