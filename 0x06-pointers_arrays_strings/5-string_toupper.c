#include "main.h"

/**
 * string_toupper - Change all lowercase to uppercase
 * @n: Pointer to the string to modify.
 * Return: Pointer to the modified string.
 */
char *string_toupper(char *n)
{
	int x = 0;

	while (n[x] != '\0')
	{
		if (n[x] >= 'a' && n[x] <= 'z')
			n[x] = n[x] - 32;
		x++;
	}
	return (n);
}
