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
	char *ptr = str;

	if (str == NULL)
		return;

	while (*ptr != '\0')
	{
		putchar(*ptr);
		ptr += 2;
	}

	putchar('\n');
}
