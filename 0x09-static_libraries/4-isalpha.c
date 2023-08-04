#include "main.h"
/**
 * _isalpha -  checks if the input alphabetic character or not.
 * @c: the character in ASCII
 *
 * Return: always 0 (success).
 */
int _isalpha(int c)
{
	if ((c > 96 && c < 123) || (c > 64 && c < 91))
	{
		return (1);
	}
	else
	{
		return (0);
	}
_putchar('\n');
}
