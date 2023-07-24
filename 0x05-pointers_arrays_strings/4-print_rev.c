#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * print_rev - Prints a string in reverse followed by a new line.
 * @s: The input string to be reversed and printed.
 */
void print_rev(char *s)
{
	int length = strlen(s);
	int i;

	for (i = length - 1; i >= 0; i--)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}
