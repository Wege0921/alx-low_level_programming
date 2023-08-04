#include "main.h"
/**
 * _islower -  checks if the input caracter is lower case or upper case.
 * @c: the character in ASCII
 *
 * Return: always 0 (success).
 */
int _islower(int c)
{
	if (c > 96 && c < 123)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
